targets=fixed_overriding refquals
CXX:=g++
CXX_FLAGS:= -Wall -std=c++17

all: $(targets)

.PHONY: $(targets) 
$(targets): 
	$(CXX) $(CXX_FLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f $(targets)



