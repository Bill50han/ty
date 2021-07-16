void test()
{
    char* addr = (char*)0xe0000000;
    for (int i = 0; i < 1440 * 20; i++)
    {
        *((char*)addr + 0) = 0xff;
        *((char*)addr + 1) = 0xff;
        *((char*)addr + 2) = 0xff;
        *((char*)addr + 3) = 0x00;
    }
    
}