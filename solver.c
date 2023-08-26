#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "aes.h"

// test.c にコピーして使う
// SBox をカスタマイズする場合は、aes.c を編集する
// make test で AES 128,192,256 の各パターンをテストできる
int main() {
    unsigned char buf[16] = {
        0x2B, 0xC8, 0x20, 0x8B, 0x5C, 0x0D, 0xA7, 0x9B, 0x2A, 0x51, 0x3A, 0xD2, 0x71, 0x71, 0xCA, 0x50
    };

    char *key = malloc(17);
    memcpy(key, "Re_1s_eaSy123456", 17);

    struct AES_ctx aesCtx;
    AES_init_ctx(&aesCtx, (uint8_t*)key);
    AES_ECB_decrypt(&aesCtx, buf);
    printf("%s\n", buf);
    // WMCTF{Re_1s_eaSy_eZ_Rc4_@nd_AES!}
    return 0;
}
 
