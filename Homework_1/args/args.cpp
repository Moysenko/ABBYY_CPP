#include "args.hpp"

namespace args {

void Parse(const std::string& sale_method_name, Args::SaleMethod& sale_method) {
    if (sale_method_name == kSaleFirst) {
        sale_method = Args::SaleMethod::kSaleFirst;
    } else {
        sale_method = Args::SaleMethod::kSaleLast;
    }
}

Args::Args(int argc, char *argv[]) {
    if (argc != 4) {
        throw std::invalid_argument("Invalid number of arguments");
    }

    std::string input_file_name = argv[1];
    std::string output_file_name = argv[2];

    input.open(input_file_name);
    output.open(output_file_name);

    if (!input) {
        throw std::invalid_argument("Can't open input file");
    }
    if (!output) {
        throw std::invalid_argument("Can't open output file");
    }

    Parse(argv[3], sale_method);
}

}  // namespace args