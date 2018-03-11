targets=scoped_enum
CXX:=g++
CXX_FLAGS:=-std=c++17

all: $(targets)

.PHONY: $(targets) 
$(targets): 
	$(CXX) $(CXX_FLAGS) $@.cpp -o $@

.PHONY: clean
clean:
	rm -f $(targets)



