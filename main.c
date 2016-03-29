/*	
 *	算法：	Aes
 *	来源：	Openssl
 *	表达式：
 *	时间：	2016.1.14
 *	作者：	孙凛
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
// #include <openssl/aes.h>
#include "aes.h"

#define DEBUG

typedef unsigned int ARCH_INDEX;
typedef unsigned int uint32_t;

int main(int argc, char *argv[]){
	char key[33] = "0123456789abcdef0123456789abcdef";
	unsigned char iv[16] = {0x2d, 0xa1, 0x20, 0xca, 0xc8, 0xa4, 0x80, 0x47, 0x13, 0x25, 0x0a, 0x1c, 0x5a, 0x58, 0xc3, 0xe6};
	// unsigned char uncrypted_contents[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	unsigned char uncrypted_contents[16] = {0x74, 0xab, 0x7c, 0x2e, 0xf4, 0x76, 0x24, 0x40, 0xfd, 0x0f, 0xdb, 0x75, 0x17, 0xe7, 0x96, 0xf5};
	unsigned char encrypted_contents_cbc[16];
	unsigned char encrypted_contents_ecb[16];
	
	
	AES_KEY akey;
	if(AES_set_encrypt_key((unsigned char *)key, 256, &akey) < 0) {
		fprintf(stderr, "AES_set_derypt_key failed!\n");
	}

#ifdef DEBUG
printf("key -> akey.rd_key: ");
for(int i=0; i<sizeof(akey.rd_key)/4; i++)
	printf("%.8x ", akey.rd_key[i]);
printf("\n");
#endif

	AES_cbc_encrypt((unsigned char *)uncrypted_contents, (unsigned char *)encrypted_contents_cbc, 16, &akey, iv, AES_ENCRYPT); // AES_DECRYPT or AES_ENCRYPT
	AES_ecb_encrypt((unsigned char *)uncrypted_contents, (unsigned char *)encrypted_contents_ecb, &akey, AES_ENCRYPT); // AES_DECRYPT or AES_ENCRYPT

#ifdef DEBUG
printf("uncrypted_contents: ");
for(int i=0; i<16; i++)
	printf("%.2x", uncrypted_contents[i]);
printf("\n");

printf("encrypted_contents_cbc: ");
for(int i=0; i<16; i++)
	printf("%.2x", encrypted_contents_cbc[i]);
printf("\n");

printf("encrypted_contents_ecb: ");
for(int i=0; i<16; i++)
	printf("%.2x", encrypted_contents_ecb[i]);
printf("\n");
#endif
	
	return 0;
}