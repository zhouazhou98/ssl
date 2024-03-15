
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <string.h>

int base64_encode(const unsigned char * in, int len, char * base64) {
    if (!in || !base64 || len <= 0)
        return 0;

    // BIO Souece: memory
    BIO * bio_mem_s = BIO_new(BIO_s_mem());
    if (!bio_mem_s) return 0;

    // BIO Filter: base64
    BIO * bio_base64_f = BIO_new(BIO_f_base64());
    if (!bio_base64_f) {
        BIO_free(bio_mem_s);
        return 0;
    }


    // BIO Link: BIO 链表，头节点 bio_base64_f ， 下一个节点 bio_mem_s
    BIO_push(bio_base64_f, bio_mem_s);

    // BIO Write
    int ret = BIO_write(bio_base64_f, in, len);
    if (ret <= 0) {
        BIO_free_all(bio_base64_f);
        return 0;
    }

    // 刷新缓冲区: 写入 BIO 链表 尾部
    int re = BIO_flush(bio_base64_f);
    if (re <= 0) {
        BIO_free_all(bio_base64_f);
        return 0;
    }

    // BIO Read
    struct buf_mem_st * buf_mem_p = 0;
    BIO_get_mem_ptr(bio_base64_f, &buf_mem_p);
    if (buf_mem_p) {
        int len = buf_mem_p->length;
        memcpy(base64, buf_mem_p->data, len);
        base64[len] = '\0';
        buf_mem_p->data = NULL;
        // 注意： 这里不能释放 BUF_MEM 内存，在 BIO_free_all 时会将该内存释放
        // BUF_MEM_free(buf_mem_p);
        BIO_free_all(bio_base64_f);
        return len;
    }
    BIO_free_all(bio_base64_f);
    return 0;

}
