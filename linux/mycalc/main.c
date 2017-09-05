#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *libcalc_handle = NULL;
    float (*myadd_method)(float,float);
    char *errorInfo;
    float result;
    float i = 10.0, j = 20.0;
    // 函数返回一个句柄，该句柄用于后续的 API 调用
    libcalc_handle = dlopen("./libcalc.so", RTLD_LAZY );
    if (!libcalc_handle){
        printf("Open Error:%s.\n",dlerror());
        return 0;
    }
    myadd_method = dlsym(libcalc_handle, "myadd");
    // 调用dlerror方法，返回错误信息的同时，内存中的错误信息被清空
    errorInfo = dlerror();
    if (errorInfo != NULL){
        printf("Dlsym Error:%s.\n",errorInfo);
        return 0;
    }
    result = (*myadd_method)(i,j);
    printf("result = %f.\n",result);
    dlclose(libcalc_handle);
    return 0;
}
