import sys
def main():
    n_str, m_str = sys.stdin.readline().split()
    n = int(n_str)
    m = int(m_str)

    print(n // m)
    print(n % m)

if __name__ == "__main__":
    main()