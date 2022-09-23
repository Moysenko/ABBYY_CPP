#include <args/args.hpp>
#include <stonks/stocks.hpp>
#include <transactions/transactions.hpp>

#include <vector>

namespace {

void solve(int argc, char *argv[]) {
    args::Args args(argc, argv);

    std::vector<stocks::StocksOperation> operations;
    stocks::StocksOperation current_operation;
    while (args.input >> current_operation) {
        operations.push_back(std::move(current_operation));
    }

    std::vector<transactions::Transaction> transactions_list = 
        transactions::GetTransactionsFromOperations(operations, args.sale_method);
    
    for (auto& transaction: transactions_list) {
        args.output << transaction << '\n';
    }
}

}  // namespace

int main(int argc, char *argv[]) {
   solve(argc, argv); 
}