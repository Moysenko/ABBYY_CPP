#include "stocks.hpp"

namespace stocks {
std::istream& operator>>(std::istream& input, StocksOperation& stocks_operation) {
    input >> stocks_operation.operation_id;

    std::string operation_type; 
    input >> operation_type;
    Parse(operation_type, stocks_operation.operation_type);
    
    input >> stocks_operation.stocks_id;
    input >> stocks_operation.stocks_count;
    input >> stocks_operation.price;

    return input;
}

void Parse(const std::string& operation_type_name, StocksOperation::OperationType& operation_type) {
    if (operation_type_name == kBuy) {
        operation_type = StocksOperation::OperationType::kBuy;
    } else {
        operation_type = StocksOperation::OperationType::kSell;
    }
}

std::string ToString(const StocksOperation::OperationType& operation_type) {
    if (operation_type == StocksOperation::OperationType::kBuy) {
        return kBuy;
    } else {
        return kSell;
    }
}

}  // namespace stocks