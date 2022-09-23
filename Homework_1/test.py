import os
import filecmp

TESTS_NUM = 3

for i in range(1, TESTS_NUM + 1):
    for sale_method in ("sale_first", "sale_last"):
        os.system(f"./build/main/Main ./tests/{i}.in ./tests/run.out {sale_method}")
        if not filecmp.cmp("./tests/run.out", f"./tests/{sale_method}_{i}.out"):
            print(f"Error at test: i={i}, sale_method={sale_method}")
            assert False

print("All tests passed")