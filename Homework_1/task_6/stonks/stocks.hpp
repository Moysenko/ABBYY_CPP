#pragma once

#include <iostream>
#include <string>

namespace stocks {

const std::string kBuy = "buy";
const std::string kSell = "sell";

struct StocksOperation {
    friend std::istream& operator>>(
        std::istream& input, StocksOperation& stocks_block);

    enum OperationType {
        kBuy,
        kSell
    } operation_type;
    int operation_id;
    std::string stocks_id;
    int stocks_count;
    int price;
};

void Parse(const std::string& operation_type_name, 
           StocksOperation::OperationType& operation_type);

std::string ToString(const StocksOperation::OperationType& operation_type);

}  // namespace stocks