typedef string str_t<255>;

struct my_result {
    str_t data;
};

program INTCONV{
    version INTCONV_1{
        my_result toHex(int) = 1;
        my_result toOct(int) = 2;
    } = 1;
} = 1;
