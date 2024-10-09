#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <sys/types.h>
#include <sys/sysctl.h>

int getProcessCount() {
    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL, 0};
    size_t size = 0;
    int processCount = 0;

    if (sysctl(mib, 4, NULL, &size, NULL, 0) == -1) {
        perror("sysctl error");
        return -1;
    }

    processCount = size / sizeof(struct kinfo_proc);
    return processCount;
}

int main() {
    while (true) {
        // 현재 시간 가져오기
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        
        // 프로세스 수 가져오기
        int processCount = getProcessCount();

        // 정보 출력
        if (processCount != -1) {
            std::cout << "현재 시간: " << std::ctime(&now_c)
                      << "프로세스 수: " << processCount << std::endl;
        } else {
            std::cout << "프로세스 수를 가져오는 데 실패했습니다." << std::endl;
        }

        // 1초 대기
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}