#pragma once

#include <iostream>
#include <string>
#include <optional>
#include <vector>

#include <args/args.hpp>
#include <stonks/stocks.hpp>

namespace transactions {

struct Transaction {
    friend std::ostream& operator<<(
        std::ostream& output, const Transaction& transaction);
    bool operator<(const Transaction& other) const;

    enum TransactionType {
        kLong,
        kShort
    } transaction_type;
    std::string stocks_id;
    int stocks_count;

    int buy_price;
    std::optional<int> sell_price;

    int buy_operation_id;
    std::optional<int> sell_operation_id;

    Transaction(TransactionType transaction_type, std::string stocks_id, 
                int stocks_count, int buy_price, std::optional<int> sell_price, 
                int buy_operation_id, std::optional<int> sell_operation_id) 
        : transaction_type{transaction_type}, stocks_id{stocks_id}, stocks_count{stocks_count},
          buy_price{buy_price}, sell_price{sell_price}, buy_operation_id{buy_operation_id},
          sell_operation_id{sell_operation_id} {}

    Transaction(const stocks::StocksOperation& operation) 
        : transaction_type{TransactionType::kLong},
          stocks_id{operation.stocks_id},
          stocks_count{operation.stocks_count},
          buy_price{operation.price},
          buy_operation_id{operation.operation_id} {}
};

std::vector<transactions::Transaction> GetTransactionsFromOperations(
        const std::vector<stocks::StocksOperation>& operations,
        args::Args::SaleMethod sale_method);

}  // namespace transactions