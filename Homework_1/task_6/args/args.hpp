#pragma once

#include <fstream>
#include <string>

namespace args {

const std::string kSaleFirst = "sale_first";
const std::string kSaleLast = "sale_last";

struct Args {
    Args(int argc, char *argv[]);

    enum SaleMethod {
        kSaleFirst,
        kSaleLast
    } sale_method;
    std::ifstream input;
    std::ofstream output;
};

void Parse(const std::string& sale_method_name, Args::SaleMethod& sale_method);

}  // namespace args