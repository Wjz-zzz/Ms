#include <cctype>
#include <cstdio>

static char inbuf[1 << 20];
static char outbuf[1 << 20];
static int inpos, inlen, outpos;

inline char gc() {
    if (inpos >= inlen) {
        inpos = 0;
        inlen = static_cast<int>(fread(inbuf, 1, sizeof(inbuf), stdin));
        if (inlen <= 0) {
            return EOF;
        }
    }
    return inbuf[inpos++];
}

inline void pc(char c) {
    if (outpos >= static_cast<int>(sizeof(outbuf))) {
        fwrite(outbuf, 1, outpos, stdout);
        outpos = 0;
    }
    outbuf[outpos++] = c;
}

inline void flush() {
    if (outpos > 0) {
        fwrite(outbuf, 1, outpos, stdout);
        outpos = 0;
    }
}

template <typename T>
inline void read(T& x) {
    x = 0;
    char c = gc();
    bool neg = false;
    while (c != EOF && c != '-' && !std::isdigit(static_cast<unsigned char>(c))) {
        c = gc();
    }
    if (c == '-') {
        neg = true;
        c = gc();
    }
    while (c != EOF && std::isdigit(static_cast<unsigned char>(c))) {
        x = x * 10 + (c - '0');
        c = gc();
    }
    if (neg) {
        x = -x;
    }
}

inline void write_str(const char* s) {
    while (*s) {
        pc(*s++);
    }
}

template <typename T>
inline void write(T x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    char s[40];
    int n = 0;
    if (x == 0) {
        s[n++] = '0';
    }
    while (x > 0) {
        s[n++] = static_cast<char>('0' + static_cast<int>(x % 10));
        x /= 10;
    }
    while (n--) {
        pc(s[n]);
    }
}

int main() {
    __int128 a, b;
    read(a);
    read(b);

    write(a + b);
    pc('\n');

    write(a * b);
    pc('\n');

    if (b == 0) {
        write_str("Division by zero\n");
    } else {
        write(a / b);
        pc('\n');
        write(a % b);
        pc('\n');
    }

    flush();
    return 0;
}
