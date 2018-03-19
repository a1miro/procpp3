


def main():
    print("\nBit manipulation examples:")

    print("\nReset far right bit:")
    x = 0b01011000
    print("x={0:#010b}".format(x))
    print("x-1 = {0:#010b}".format(x-1))
    print("x & (x-1) = {0:#010b}".format(x & (x-1)))

    print("\nCheck if either number forms 2^n-1, return 0 if it is")
    x=(1<<3)-1
    print("x={0:#010b}".format(x))
    print("x+1 = {0:#010b}".format(x+1))
    print("x & (x+1) = {0:#010b}".format(x & (x+1)))

    x=(1<<3)
    print("x={0:#010b}".format(x))
    print("x+1 = {0:#010b}".format(x+1))
    print("x & (x+1) = {0:#010b}".format(x & (x+1)))

    print("\nCheck if either number forms 2^n, return 0 if it is")
    x=(1<<3)
    print("x={0:#010b}".format(x))
    print("x-1 = {0:#010b}".format(x-1))
    print("(x-1) & x = {0:#010b}".format(x & (x-1)))

    x=(1<<3)+3
    print("x={0:#010b}".format(x))
    print("x-1 = {0:#010b}".format(x-1))
    print("(x-1) & x = {0:#010b}".format(x & (x-1)))

    print("\nSetting up bit mask from bit 0 to bit n")
    n=5
    mask=1<<n
    print("n={0:d}".format(n))
    print( "1<<n ^ ((1<<n) -1) = {0:#010b}".format(mask ^ (mask -1)))


    print("\nReset all bits from bit n to bit 0")
    x=0b00111111
    n=3
    print("x={0:#010b}".format(x))
    print("n={0:d}".format(n))

    mask = 1<<n
    print("x & ~(mask ^ (mask -1)) = {0:#010b}".format(x & ~(mask ^ (mask -1))))



    print("\nGenerate bit mask from bit m to bit n (m>n)")
    m = 5
    n = 3

    print("m={0:d}".format(m))
    print("n={0:d}".format(n))
    mask_m = 1 << m
    mask_m = mask_m ^ (mask_m -1)

    mask_n = 1 << n-1 

    mask = mask_m & ~(mask_n ^ (mask_n -1))

    print("mask={0:#010b}".format(mask))


    











if __name__ == "__main__":
    main()
