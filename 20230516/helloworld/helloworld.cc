#include <iostream>

#include <CL/cl.h>

int main(void)
{
    cl_int err = CL_SUCCESS;
    cl_uint numPlatforms = 0;

    err = clGetPlatformIDs(0, nullptr, &numPlatforms);

    if(err == CL_SUCCESS)
    {
        std::cout << numPlatforms << " Platfoms Found!\n";
    }
    else
    {
        std::cout << "Error Code: " << err << "\n";
    }

    return 0;
}