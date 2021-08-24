#include <libc.h>
#include <intrin.h>

void* memset(
    _OUT_   void* dst,
    _IN_    int    val,
    _IN_    size_t size
)
{
    __stosd(dst, val, size);
    return dst;
}

void* memcpy(
    _OUT_   void* dst,
    _IN_    void const* src,
    _IN_    size_t size
)
{
    __writeeflags(__readeflags() & 0xFFFFFBFF); //cld
    __movsb(dst, src, size);
    return dst;
}

errno_t memcpy_s(
    _OUT_   void* dst,
    _IN_    size_t dstMaxLen,
    _IN_    void const* src,
    _IN_    size_t size
)
{

}

void* memmove(
    _OUT_   void* dst,
    _IN_    void const* src,
    _IN_    size_t size
)
{
    __writeeflags(__readeflags() | 1024); //std
    __movsb(dst + size - 1, src + size - 1, size);
    __writeeflags(__readeflags() & 0xFFFFFBFF); //cld
    return dst;
}