targets=deduction1 deduction2 deduction3 array_arguments function_arguments
CXX:=g++
CXX_FLAGS:=-std=c++14

all: $(targets)

.PHONY: $(targets) 
$(targets): 
	$(CXX) $(CXX_FLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f $(targets)



