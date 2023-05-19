#include <CL/opencl.hpp>
#include <iostream>
#include <fstream>

int main(void)
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    for(auto &p : platforms)
    {
        std::string platName = p.getInfo<CL_PLATFORM_NAME>();
        std::cout << "Platform Name: " << platName << std::endl;
    }

    std::ifstream clSource("hellokernel.cl");
    std::string sourceCode = std::string(std::istreambuf_iterator<char>(clSource), std::istreambuf_iterator<char>());
    cl::Program::Sources source(1, sourceCode.c_str());

    cl::Program program = cl::Program(source);

    program.build();

    auto setA = cl::KernelFunctor<>(program, "setA");
    setA(cl::EnqueueArgs(cl::NDRange(1)));

    return 0;
}