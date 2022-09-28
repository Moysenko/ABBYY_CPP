#include "transactions.hpp"
#include "../args/args.hpp"

#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iterator>

namespace transactions {

namespace {

const std::string kShort = "short";
const std::string kLong = "long";

std::vector<Transaction> GetTransactions(
        args::Args::SaleMethod sale_method,
        std::deque<stocks::StocksOperation>& stocks_deque,
        stocks::StocksOperation operation) {
    std::vector<Transaction> transactions;
    bool is_long = stocks_deque.front().operation_type == stocks::StocksOperation::kBuy;

    while (!stocks_deque.empty() && operation.stocks_count > 0) {
        stocks::StocksOperation prev_operation;
        if (sale_method == args::Args::SaleMethod::kSaleFirst) {
            prev_operation = std::move(stocks_deque.front());
            stocks_deque.pop_front();
        } else {
            prev_operation = std::move(stocks_deque.back());
            stocks_deque.pop_back();
        }

        transactions.emplace_back(
            is_long ? Transaction::TransactionType::kLong : Transaction::TransactionType::kShort,
            operation.stocks_id,
            std::min(operation.stocks_count, prev_operation.stocks_count),
            prev_operation.price,
            operation.price,
            prev_operation.operation_id,
            operation.operation_id
        );


        if (prev_operation.stocks_count > operation.stocks_count) {
            prev_operation.stocks_count -= operation.stocks_count;
            sale_method == args::Args::SaleMethod::kSaleFirst ? 
                stocks_deque.push_front(prev_operation) :
                stocks_deque.push_back(prev_operation);
            operation.stocks_count = 0;
        } else {
            operation.stocks_count -= prev_operation.stocks_count;
        }
    }

    if (stocks_deque.empty() && operation.stocks_count > 0) {
        stocks_deque.push_back(std::move(operation));
    }

    return transactions;
}

std::string ToString(Transaction::TransactionType transaction_type) {
    if (transaction_type == Transaction::TransactionType::kShort) {
        return kShort;
    } else {
        return kLong;
    }
}

}  // namespace

std::ostream& operator<<(
        std::ostream& output, const Transaction& transaction) {
    std::string delimeter = " ";
    output << transaction.stocks_id << delimeter
           << transaction.stocks_count << delimeter
           << transaction.buy_price << delimeter;

    if (transaction.sell_price) {
        int income = (*transaction.sell_price - transaction.buy_price) 
                        * transaction.stocks_count;
        if (transaction.transaction_type == Transaction::TransactionType::kShort) {
            income = -income;
        } 
        output << *transaction.sell_price << delimeter << income << delimeter;
    } else {
        output << "-" << delimeter << "-" << delimeter;
    }

    output << ToString(transaction.transaction_type) << delimeter;

    output << transaction.buy_operation_id << delimeter;

    if (transaction.sell_operation_id) {
        output << *transaction.sell_operation_id;
    }

    return output;
}

bool Transaction::operator<(const Transaction& other) const {
    if (stocks_id < other.stocks_id) {
        return true;
    } else if (stocks_id == other.stocks_id) {
        auto first_sell_id = sell_operation_id.value_or(INT32_MAX);
        auto second_sell_id = other.sell_operation_id.value_or(INT32_MAX);

        if (first_sell_id < second_sell_id) {
            return true;
        } else if (first_sell_id == second_sell_id) {
            return buy_operation_id < other.buy_operation_id;
        }
    } 

    return false;
}

std::vector<transactions::Transaction> GetTransactionsFromOperations(
        const std::vector<stocks::StocksOperation>& operations,
        args::Args::SaleMethod sale_method) {
    std::unordered_map<std::string, std::deque<stocks::StocksOperation>> 
        operations_map;
    std::vector<Transaction> transactions;
    
    for (const auto& operation: operations) {
        auto& stocks_deque = operations_map[operation.stocks_id];
        if (stocks_deque.empty() || 
                stocks_deque.front().operation_type == operation.operation_type) {
            stocks_deque.push_back(operation);
            continue;
        }

        auto transactions_to_add = GetTransactions(sale_method, stocks_deque, operation);
        transactions.insert(transactions.end(), 
                    std::make_move_iterator(transactions_to_add.begin()),
                    std::make_move_iterator(transactions_to_add.end()));
    }

    for (const auto& [stock_id, stocks_deque] : operations_map) {
        if (stocks_deque.empty() || 
                stocks_deque.front().operation_type != stocks::StocksOperation::OperationType::kBuy) {
            continue;
        }

        for (const auto& operation: stocks_deque) {
            transactions.emplace_back(operation);
        }
    }

    sort(transactions.begin(), transactions.end());

    return transactions;
}
}  // transactions