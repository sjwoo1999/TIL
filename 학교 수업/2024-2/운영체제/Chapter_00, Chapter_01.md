## 00 Course Introduction.OS

### What is an Operating System?

운영체제 : 컴퓨터 하드웨어를 동작시키는 소프트웨어.

user

appllication

os

hardware

### Operating Systems 1 - Introduction

모든 프로세스, 파일, 메모리의 섹션, 장치를 컨트롤한다.

OS

- Process Manager
    - How to allocate prain ..
    - Keep track status
- Memory Manager
    - Main Memory
    - Memory allocation
- File Manager
    - check every file type ..
    - Read/write/execute
- Device Manager
    - allocate system device ..
- Network Manager
    - Share hardware and software …

### From Windows 1 To Windows 10 : 30 Years of OS History

### Course Summary

- The Operating System is an essential part of any computer system which is a program that manages the computer hardware.
- It executes user programs and allocates various system resources such as processor, memory space, and peripheral devices.
- This course introduces the basic concepts of Operating Systems.
- Thes concepts lead to intersting of Process and threads, deadlocks, memory management, input/output, file systems.

### Course Objectives

Understanding the role of OS in a computer system : Lectures, Exams

## Chapter 1 : Introduction

### Contents

- Organization
- Architecture
- Structure
- Operations

- Process Management
- Storage Management
- Environmnet Management

- Protection and Security
- Distributed Systems
- Computing Environments

### Objectives

- To provide a grand tour of the **major operating systems components**
- To provide coverage of **basic computer system organization**

### What is an Operating System?

- A **program** that acts as an **intermediary** between a user of computer and the computer hardware.
    - HW와 사용자의 중간자 역할을 한다.
- Operating system goals:
    - Execute user programs and make solving user problems easier.
    사용자의 프로그램을 실행시키고 문제를 쉽게 해결할 수 있도록 돕는다.
    기본적으로 컴퓨터는 계산기에서부터 출발했고 문제를 해결하기 위한 도구로써 만들어졌다.
        - Process management
    - Use the computer hardware in an efficient manner.
    컴퓨터 하드웨어를 효율적으로 사용할 수 있도록 한다.
        - Resource management
        - Storage, Memory, I/O
        - 자원(저장소, 메모리, 입출력)을 관리한다.
    - Make the computer system convenient to use.
    컴퓨터 시스템을 사용하기에 편리하도록 만든다.
        - Environment management

### Current Operating Systems in the World

### Computer System Structure

- Computer System can be divided into four components

- Hardware - provides basic computing resources
기본적인 연산 자원을 제공한다
    - CPU, memory, I/O devices
- Operating System
    - controls and coordinates use of hardware among various applications and users
    다양한 애플리케이션과 사용자 간의 하드웨어의 사용을 제어하고 조정한다
- Application programs
    - define the ways in which the system resources are used to solve the computing problems of the users
    시스템 리소스를 사용하여 사용자의 컴퓨팅 문제를 해결하는 방법을 정의
    - Word processors, compilers, web browsers, database systems, video games, media players, and so forth.
- Users
    - People, machines, other computers

![Screenshot 2024-10-09 at 14.46.44.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/29da16a7-1e4c-4f3b-b6ba-3e259628961b/Screenshot_2024-10-09_at_14.46.44.png)

### Operating System Definition

- OS is a resource allocator
운영체제는 리소스 할당자이다.
    - manages all resources
    - decides between conflicting requests **for efficient and fair resource use**
    충돌하는 요청들 사이에서 효율적이고 공평한 자원 사용을 결정한다.

- Os is a control program
운영체제는 조작하는 프로그램이다
    - controls execution of programs to **prevent errors and improper use of the computer**
    프로그램 실행을 제어하여 컴퓨터의 에러와 부적절한 사용을 방지한다.

- No universally accepted definition
보편적으로 수용된 정의는 없다.

- “Everything a vendor ships when you order an operating system” is good approximation
”운영체제를 주문할 때 공급업체가 제공하는 모든 것”은 좋은 근사치입니다.
    - But varies wildly
    하지만 크게 다를 수 있습니다.

### Computer Startup
컴퓨터 시작

- Bootstrap program is loaded at power-up or reboot
부트스트랩
    - Initial program to run.
    실행되는 최초의 프로그램
    - Typically stored in ROM or EEPROM generally known as firmware
    일반적으로 ROM 또는 EEPROM에 저장되며, 이를 펌웨어(firmware)라고 부름.
    - initialize all aspects of system: system diagnostics
    시스템의 모든 측면을 초기화 : 시스템 진단 수행.
    - loads operating system kernel into memory and starts execution
    운영 체제 커널을 메모리에 로드하고 실행을 시작함.
        - Sometimes, execute boot block code, the boot block loads OS and execute.
        때로는 부트 블록 코드를 실행하며, 부트 블록이 운영 체제를 로드하고 실행함.
    - From now on, computer is under control of OS kernel.
    이후 컴퓨터는 운영체제 커널의 제어 하에 있음.

- Operating System
    - executes the first process, such as “init”
    첫 번째 프로세스를 실행함, 예를 들어 “init” 같은 프로세스
    - watis for some event to occur.
    어떤 이벤트가 발생하길 기다림

### Computer System Organization
컴퓨터 시스템 조직

- Computer-system hardware components
컴퓨터 시스템 하드웨어 구성 요소
    - One or more CPUs, device controllers connected through common bus providing access to shared memory
    공유 메모리에 대한 액세스를 제공하는 하나 이상의 CPU, 공통 버스를 통해 연결된 장치 컨트롤러
    - Concurrent execution of CPUs and devices competing for memory cycles
    메모리 주기를 놓고 경쟁하는 CPU와 디바이스의 동시 실행

✔ Controller

데이터 전송 준비가 되면, interrupt 발생.
CPU에게 내가 메모리로부터 데이터 전송을 할 준비가 되어있다라는 것을 알려주고,
그 interrupt를 통해서 Controller가 데이터 전송의 허가를 받고 데이터 전송을 진행하게 되는 것.

✔️ CPU와 Controller는 메모리에 데이터 저장을 서로 경쟁을 하며 동작을 한다.
     동일한 Bus를 공유하며 사용한다.
     CPU와 Controller가 동시에 사용하면 충돌이 발생할 수 있으며, 이런 충돌 해결법 : interrupt

![Screenshot 2024-10-09 at 15.01.12.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/19331fb0-eb54-4039-b792-33ac563a8bea/Screenshot_2024-10-09_at_15.01.12.png)

### North and South bridge

- 노스브리지 [North bridge]
    - 노스브리지 MCH(Memory Controller Hub)는 메모리 인터페이스와 그래픽카드 인터페이스를 컨트롤한다.
- 사우스브리지 [South bridge]
    - 사우스브리지 ICH(I/O Controller Hub)는 슬롯(Slot)-ISA, ELSA, PCI과 HDD, USB, PS2 등을 컨트롤한다.

![Screenshot 2024-10-09 at 15.02.29.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/d5ee560c-db3d-4a54-89ee-3bb7b7948af7/Screenshot_2024-10-09_at_15.02.29.png)

### Computer System Operations
컴퓨터 시스템 작동

- I/O devices and the CPU can execute concurrently.
I/O 장치와 CPU는 동시에 실행될 수 있음.
- Each device controller is in charge of a particular device type.
각 장치 컨트롤러는 특정 장치 유형을 담당함.
- Each device controller has a local buffer.
각 장치 컨트롤러는 로컬 버퍼를 가지고 있음.
- CPU moves data from/to main memory to/from local buffers
CPU는 메인 메모리와 로컬 버퍼 간에 데이터를 이동시킴.
- I/O is a data transfer from the device to local buffer of controller.
I/O는 장치에서 컨트롤러의 로컬 버퍼로 데이터 전송을 의미함.
- Device controller informs CPU that it has finished its operation by causing an interrupt
장치 컨트롤러는 인터럽트를 발생시켜 CPU에 작업이 완료되었음을 알림.

### Interrupt
인터럽트

- The occurrence of an event is usually signaled by an interrupt from either the hardware and the software.
이벤트의 발생은 일반적으로 하드웨어나 소프트웨어로부터의 인터럽트로 신호가 전달됨.
    - Hardware may trigger an interrupt at any time by sending signal to the CPU (device controller, timer)
    하드웨어는 장치 컨트롤러나 타이머와 같은 요소를 통해 언제든지 CPU에 신호를 보내 인터럽트를 발생시킬 수 있음.
    - Software may trigger an interrupt by executing a special operation called a system call
    소프트웨어는 시스템 호출(system call)이라는 특별한 작업을 실행하여 인터럽트를 발생시킬 수 있음.

- When the CPU is interrupted
CPU가 인터럽트를 받을 때
    - stops what it is doing
    현재 수행 중인 작업을 중단함.
    - immediately transfers execution to a fixed location
    즉시 고정된 위치로 실행을 전송함.
    - the fixed location usually contains the starting address where the service routine for the interrupt is located
    그 고정된 위치는 일반적으로 인터럽트에 대한 서비스 루틴이 위치한 시작 주소를 포함함.
    - executes the interrupt service routine
    인터럽트 서비스 루틴을 실행함.
    - resumes the interrupted computation on completion.
    완료 후 중단된 연산을 다시 수행함.

### Common Functions of Interrupt
인터럽트의 일반적인 기능

- Interrupt transfers control to the interrupt service routine generally, through the interrupt vector, which contains the addresses of all the interrupt service routines.
인터럽트는 일반적으로 인터럽트 벡터를 통해 제어를 인터럽트 서비스 루틴으로 전송하며, 이 벡터에는 모든 인터럽트 서비스 루틴의 주소가 포함되어 있음.
    - 다양한 종류의 interrupt가 정의되어 있고, 각 interrupt 종류마다 실행되어야 하는 코드가 다르다. C 프로그램을 할 때 정의한 function이다. 라고 생각하면 되겠다.
- Interrupt architecture must save the address of the interrupted instruction
인터럽트 아키텍처는 인터럽트된 명령어의 주소를 저장해야 함.
- 멈췄다가 다시 실행하기 위해서 주소를 저장해둔다.
    - by storing registers and the program counter.
    이를 위해 레지스터와 프로그램 카운터를 저장함.
    - 레지스터와 프로그램 카운터에 대한 정보
- Incoming interrupts are disabled while another interrupt is being processed to prevent a lost interrupt.
인터럽트 처리 중에 다른 인터럽트가 발생할 경우, 인터럽트가 손실되지 않도록 들어오는 인터럽트를 비활성화함.
- Interrupt가 발생했을 땐 다른 Interrupt가 발생할 수 없음
- A trap is a software-generated interrupt caused either by an error or a user request.
트랩(trap)은 오류 또는 사용자 요청으로 발생하는 소프트웨어 생성 인터럽트임.
- system call로 발생하는 software interrupt는 trap이다.
- An operating system is interrupt driven.
운영체제는 인터럽트 구동 방식으로 작동함.

### Interrupt Service Routine
인터럽트 서비스 루틴

- Each computer has its own interrupt mechanism, but several functions are common
각 컴퓨터는 고유한 인터럽트 메커니즘을 가지고 있지만, 몇 가지 공통된 기능이 있음
    - Generic routine
    일반적인 루틴
    - interrupt service routine (**`interrupt-specific handler`**)
    인터럽트 서비스 루틴(인터럽트 전용 핸들러)

- invoke a generic routine to examine the interrupt information
일반 루틴을 호출하여 인터럽트 정보를 검사함.
- call the interrupt-specific handler.
인터럽트 전용 핸들러를 호출함.
- Interrupts must be handled quickly.
인터럽트는 신속하게 처리되어야 함.
    - Only predefined number of interrupts are possible
    사전에 정의된 수의 인터럽트만 가능함.
    - A table of pointers to interrupt handler is used
    인터럽트 핸들러에 대한 포인터 테이블이 사용됨.
        - Interrupt vector table
        이를 인터럽트 벡터 테이블이라고 함.
    - The table of pointers is sorted in low memory location
    이 포인터 테이블은 낮은 메모리 위치에 정렬되어 있음.

![Screenshot 2024-10-09 at 15.54.01.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/034a95a3-487a-4066-b365-21e22f219738/Screenshot_2024-10-09_at_15.54.01.png)

[Claude]

이 이미지는 인터럽트 처리 과장의 시간 흐름을 보여줍니다. 단계별로 살펴보겠습니다:

1. 초기 상태:
    1. CPU : 사용자 프로세스 P1을 실행 중입니다.
    2. I/O 장치 : 유휴 상태입니다.
2. I/O 요청 발생:
    1. CPU가 I/O 요청을 합니다.
    2. I/O 장치가 데이터 전송을 시작합니다.
    3. CPU는 계속해서 P1을 실행합니다.
3. 인터럽트 발생:
    1. I/O 장치가 데이터 전송을 완료합니다.
    2. 인터럽트가 발생하여 CPU에 신호를 보냅니다.
4. 인터럽트 처리:
    1. CPU가 P1의 실행을 중단하고 인터럽트 처리를 시작합니다.
    2. 로컬 버퍼의 데이터가 메인 메모리로 전송됩니다.
5. 인터럽트 처리 완료:
    1. CPU가 인터럽트 처리를 마치고 P1의 실행을 재개합니다.
6. 두 번째 I/O 요청 및 처리:
    1. 과정이 반복됩니다.

이 타임라인은 인터럽트가 CPU 작업과 I/O 작업을 어떻게 효율적으로 병행 처리하는지 보여줍니다.

![Screenshot 2024-10-09 at 15.54.18.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/23dbf4e2-c318-4a78-82fc-e6dfbaf3a248/Screenshot_2024-10-09_at_15.54.18.png)

이 이미지는 인터럽트 처리의 하드웨어 및 소프트웨어 구성 요소를 보여줍니다.

1. I/O 장치 (HDD, SSD):
    1. 데이터를 저장하고 읽어오는 물리적 장치입니다.
2. 장치 컨트롤러:
    1. I/O 장치와 시스템 간의 인터페이스 역할을 합니다.
    2. 로컬 버퍼와 레지스터를 포함하여 데이터를 임시 젖아합니다.
3. 메인 메모리:
    1. 프로세스 실행에 필요한 데이터를 저장합니다.
4. CPU:
    1. 프로세스를 실행하고 인터럽트를 처리합니다.
5. 인터럽트 벡터 테이블
    1. 각 인터럽트 유형에 대한 처리 루틴의 주소를 저장합니다.
6. 장치 드라이버
    1. 특정 I/O 장치와 통신하기 위한 소프트웨어 인터페이스입니다.
7. 인터럽트 특정 핸들러
    1. 각 인터럽트 유형에 대한 세부적인 처리 로직을 포함합니다.
8. 프로세스
    1. 시스템 호출을 통해 I/O 작업을 요청합니다.

이 구조는 하드웨어 인터럽트가 어떻게 소프트웨어 레벨의 처리로 연결되는지 보여줍니다.

![Screenshot 2024-10-09 at 15.54.34.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/cd3007f6-c213-47f5-bb45-b0dacd2c834a/Screenshot_2024-10-09_at_15.54.34.png)

이 이미지는 인터럽트 처리 중 데이터의 흐름을 보여줍니다.

1. 데이터 읽기:
    1. I/O 장치에서 데이터를 읽어 장치 컨트롤러의 로컬 버퍼로 전송합니다.
2. 인터럽트 발생:
    1. 데이터 전송이 완료되면 장치 컨트롤러가 CPU에 인터럽트를 보냅니다.
3. CPU 응답:
    1. CPU가 현재 프로세스의 실행을 중단하고 인터럽트 처리를 시작합니다.
4. 데이터 전송:
    1. 인터럽트 핸들러가 로컬 버퍼의 데이터를 메인 메모리로 전송합니다.
5. 프로세스 재개:
    1. 데이터 전송이 완료되면 CPU가 원래 프로세스의 실행을 재개합니다.

이 과정은 I/O 작업과 CPU 작업이 어떻게 병렬로 처리되는지, 그리고 인터럽트가 어떻게 이 두 작업을 조율하는지 보여줍니다.

![Screenshot 2024-10-09 at 16.07.16.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/b4dea99c-e4fd-4a5f-b89e-1e403220f5bd/Screenshot_2024-10-09_at_16.07.16.png)

흠 …

### I/O Structure

- What is I/O
I/O(입출력)란 무엇인가
    - Input and Output
    입력(Input)과 출력(Output)을 의미함.
    - Data transfer in between devices and memory/local buffer
    장치와 메모리 또는 로컬 버퍼 간의 데이터 전송
    - Devices include keyboard, monitor, mouse, disk, etc.
    장치에는 키보드, 모니터, 마우스, 디스크 등이 포함됨.
- Device Controller
장치 컨트롤러
    - A hardware which is connected to the common bus
    공통 버스에 연결된 하드웨어.
    - One or more devices are connected to a device controller
    하나 이상의 장치가 장치 컨트롤러에 연결됨.
    - maintains some local buffer storage and a set of special-purpose registers
    로컬 버퍼 저장소와 특수 목적 레지스터 세트를 유지함.
    - is responsible for moving the data between the peripheral devices and its local buffer storage
    주변 장치와 로컬 버퍼 저장소 간의 데이터 이동을 담당함.
- Device Driver
장치 드라이버
    - A operating system has a device driver for each device controller
    운영 체제는 각 장치 컨트롤러에 대해 장치 드라이버를 가짐.
    - understands the device controller
    장치 컨트롤러를 이해함.
    - provides a uniform interface for the device to the rest of the OS
    장치와 운영 체제 간에 일관된 인터페이스를 제공함.

### I/O Structure
I/O 구조

- To start an I/O operation
I/O 작업을 시작하려면
    - The device driver sets the appropriate registers within the device controller
    장치 드라이버가 장치 컨트롤러 내의 적절한 레지스터를 설정함.

- The device controller examines the contents
장치 컨트롤러는 그 내용을 검사함.
- The device controller starts the transfer of data from the device to its local buffer
장치 컨트롤러는 장치에서 로컬 버퍼로 데이터 전송을 시작함.
- On completion, the device controller informs the device driver via interrupt.
완료되면, 장치 컨트롤러는 인터럽트를 통해 장치 드라이버에 작업 완료를 알림.

- The device driver returns control to the OS
장치 드라이버는 제어를 운영 체제에 반환함.
- OS read the data
운영 체제는 데이터를 읽음.

- Synchronous I/O
동기식 I/O
    - After I/O starts, control returns to user program only upon I/O completion.
    I/O 작업이 시작된 후, I/O가 완료될 때만 사용자 프로그램에 제어가 반환됨.
    - Wait instruction idles the CPU until the next interrupt
    CPU는 대기 명령을 통해 다음 인터럽트가 발생할 때까지 유휴 상태로 유지됨.

- Asynchronous I/O
비동기식 I/O
    - After I/O starts, control returns to user program without waiting for I/O completion.
    I/O 작업이 시작된 후, I/O 완료를 기다리지 않고 사용자 프로그램에 제어가 반환됨.

### Two I/O Methods

- Synchronous I/O
    - I/O 시작되는 동안 멈춰 있고
- Asynchronous I/O
    - I/O 진행되는 사이에 다른 일을 동시에 한다.

- User Process uses Synchronous I/O
- Operating System uses Asynchronous I/O

→ 어떤 의미일지 생각해보세요

[ChatGPT o1-preview]

“사용자 프로세스는 동기식 I/O를 사용하고, 운영 체제는 비동기식 I/O를 사용한다”는 문장은 다음과 같은 의미와 함의를 가지고 있습니다.

의미

1. 사용자 프로세스와 동기식 I/O

- 동기식 I/O 사용
    - 사용자 프로세스는 I/O 작업을 요청하면 해당 작업이 완료될 때까지 대기합니다.
    - 이 동안 프로세스는 다른 작업을 수행하지 않고 멈춰 있습니다.
- 프로그래밍의 단순성
    - 동기식 I/O는 플그래밍 모델을 단순하게 만들어 줍니다.
    - 개발자는 I/O 작업의 완료 여부를 신경 쓰지 않고도 순차적인 코드 흐름을 작성할 수 있습니다.
- 예시
    - 파일에서 데이터를 읽는 함수 호출 후, 데이터가 완전히 읽혀질 때까지 다음 코드로 진행하지 않습니다.

1. 운영체제와 비동기식 I/O

- 비동기식 I/O 사용
    - 운영 체제는 I/O 작업을 시작한 후 그 작업의 완료를 기다리지 않고 즉시 다른 작업을 수행합니다.
- 효율적인 자원 활용
    - 비동기식 I/O를 통해 운영 체제는 CPU와 메모리 같은 시스템 자원을 효율적으로 사용합니다.
    - I/O 장치의 속도는 CPU에 비해 매우 느리기 때문에, 대기 시간을 줄이는 것이 중요합니다.
- I/O 완료 처리
    - I/O 작업이 완료되면 인터럽트나 신호를 통해 운영 체제에 알리고, 운영 체제는 해당 작업의 후속 처리를 진행합니다.

**함의**

- 사용자 경험과 시스템 효율성의 균형
    - 사용자 프로세스 측면
        - 동기식 I/O를 사용함으로써 프로그래머는 복잡한 동시성 제어를 고민하지 않아도 됩니다.
        - 코드의 가독성과 유지 보수성이 높아집니다.
    - 운영체제 측면
        - 비동기식 I/O를 통해 시스템 전체의 효율성을 높입니다.
        - 여러 I/O 작업을 병렬로 처리하거나 CPU를 다른 프로세스에 할당하여 자원의 활용도를 극대화합니다.

- 성능 최적화
    - 병목 현상 완화
        - I/O 작업은 일반적으로 느리기 때문에, 운영 체제가 비동기식으로 처리하면 I/O로 인한 병목 현상을 줄일 수 있습니다.
    - 멀티태스킹
        - 비동기식 I/O는 멀티태스킹 환경에서 필수적입니다. 여러 프로세스가 동시에 실행되면서도 시스템 자원이 효율적으로 배분됩니다.

- 프로그래밍 모델의 추상화
    - 동기식 인터페이스 제공
        - 운영 체제는 사용자 프로세스에게 동기식 I/O 인터페이스를 제공하지만, 내부적으로는 비동기식으로 처리합니다.
    - 복잡성 숨김
        - 이렇게 함으로써 프로그래머는 복잡한 비동기 처리 로직을 직접 구현할 필요 없이 간단한 방식으로 I/O를 사용할 수 있습니다.

**결론**

- 사용자 프로세스는 동기식 I/O를 사용하여 프로그래밍의 편의성과 단순성을 얻습니다. 이는 프로세스가 I/O 작업의 완료를 기다리는 방식을 의미합니다.
- 운영 체제는 비동기식 I/O를 사용하여 시스템 자원을 효율적으로 관리하고 전체적인 성능을 향상시킵니다. 이는 I/O 작업이 진행되는 동안에도 다른 작업을 수행할 수 있음을 의미합니다.
- 의미하는 바
    - 이 두 가지 접근 방식은 사용자에게는 사용의 편의성을 제공하고, 시스템 측면에서는 자원의 효율적 활용을 통해 성능을 최적화합니다.
    - 이는 운영체제가 사용자 프로세스의 요구와 시스템 효율성 사이에서 균형을 맞추고 있음을 보여줍니다.

이러한 구조는 현대 운영체제의 핵심적인 특징 중 하나로, 사용자 경험을 향상시키면서도 시스템의 효율성을 유지하는 데 기여합니다.

### Direct Memory Access (DMA)
직접 메모리 접근 (DMA)

- used for high-speed I/O devices
고속 I/O 장치에 사용됨
    - able to transmit information at close to memory speeds.
    메모리 속도에 가까운 속도로 정보를 전송할 수 있음.

- Device controller transfers blocks of data from buffer storage directly to main memory without CPU intervention.
장치 컨트롤러는 CPU의 개입 없이 버퍼 저장소에서 메인 메모리로 데이터 블록을 직접 전송함.

- Only interrupt is generated per block, rather than one interrupt per byte.
바이트마다 인터럽트를 발생시키는 대신, 블록마다 한 번의 인터럽트만 발생함.
    - improves the performance of DMA.
    이는 DMA의 성능을 향상시킴.

### Storage Structure
저장 구조

- Main memory - only large storage media that the CPU can access directly. (outside CPU)
메인 메모리 : CPU가 직접 접근할 수 있는 유일한 대용량 저장 매체 (CPU 외부에 위치함).

- Secondary storage - extension of main memory that provides large nonvolatile storage capacity.
보조 저장 장치 : 메인 메모리의 확장으로, 큰 용량의 비휘발성 저장 공간을 제공함.
    - Magnetic disk are used for the secondary storage
    보조 저장 장치로는 자기 디스크(magnetic disk)가 사용됨.

- Magnetic disks - rigid metal or glass platters covered with magnetic recording material
자기 디스크 : 금속 또는 유리 플래터(platter)에 자기 기록 재료가 덮여 있음.
    - Disk surface is logically divided into tracks, which are subdivided into sectors.
    디스크 표면은 논리적으로 트랙으로 나뉘고, 트랙은 다시 섹터로 세분화됨.
    - The disk controller determines the logical interaction between the device and the computer.
    디스크 컨트롤러는 장치와 컴퓨터 간의 논리적 상호작용을 결정함.

![Screenshot 2024-10-09 at 16.43.26.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/e3889f54-5740-4633-bec2-0563140e624e/Screenshot_2024-10-09_at_16.43.26.png)

### Storage Hierarchy
저장 계층 구조

- Storage systems organized in hierarchy
저장 시스템은 다음과 같은 기준으로 계층적으로 조직됨
    - Speed
    속도
    - Cost
    비용
    - Volatility
    휘발성 - 전원 끄면 사라지냐?

- Caching - copying information into faster storage system;
캐싱(임시 저장) : 더 빠른 저장 시스템으로 정보를 복사하는 과정.
main memory can be viewd as a last cache for secondary storage.
메인 메모리는 보조 저장 장치를 위한 마지막 캐시로 간주될 수 있음.

![Screenshot 2024-10-09 at 16.46.37.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/88ebfa0d-5932-47e6-a26b-84bfaea1d8f1/Screenshot_2024-10-09_at_16.46.37.png)

### Caching
캐싱

- Important principle, performed at many levels in a computer (in hardware, operating system, software)
중요한 원칙으로, 컴퓨터의 여러 계층에서 수행됨 (하드웨어, 운영체제, 소프트웨어에서 적용됨).
- Information in use copied from slower to faster storage temporarily
사용 중인 정보는 느린 저장소에서 빠른 저장소로 임시 복사됨.
- Faster storage (cache) check first to determine if information is there
빠른 저장소(캐시)에서 먼저 정보를 확인하여 캐시에 있는지 검사함.
    - If it is, information used directly from the cache (fast)
    정보가 있으면 캐시에서 직접 사용됨 (빠름).
    - If not, data copied to cache and used there (slow)
    정보가 없으면 데이터를 캐시에 복사한 후 그곳에서 사용됨 (느림).
- Cache smaller than storage being cached
캐시는 캐싱되는 저장소보다 작음.
    - Cache management important design problem
    캐시 관리는 중요한 설계 문제임.
    - Cache size and replacement policy
    캐시 크기와 교체 정책이 설계의 핵심 요소임. → 꽉 찼을 때 어떤 걸 지울 것인가?

![Screenshot 2024-10-09 at 16.50.32.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/8e7fd8c5-4fde-46f5-a7d3-24ca3022a846/Screenshot_2024-10-09_at_16.50.32.png)

### Migration of Integer A from Disk to Register
정수 A의 디스크에서 레지스터로의 이동

- Multitasking environments must be careful to use most recent value, not matter where it is stored in the storage hierarchy
멀티태스킹 환경에서는 저장 계층 어디에 있든지 관계없이 최신 값을 사용해야 함.

- Multiprocessor environment must provide cache coherency in hardware such that all CPUs have the most recent value in their cache
멀티프로세스 환경에서는 하드웨어에서 캐시 일관성(cache coherency)을 보장해야 하며, 모든 CPU가 캐시에서 최신 값을 가져야 함.

- Distributed environment situation even more complex
분산 환경에서는 상황이 더욱 복잡해짐.
    - Several copies of a datum can exist
    데이터의 여러 복사본이 존재할 수 있기 때문임.

![Screenshot 2024-10-09 at 16.55.40.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/d1821a7b-52f7-4abe-8ccb-25703531e874/Screenshot_2024-10-09_at_16.55.40.png)

### Computer System Architecture
컴퓨터 시스템 아키텍처

- Single-processor systems
단일 프로세서 시스템
    - One main CPU
    하나의 주요 CPU를 가짐
    - Variety of single-processor systems: from PDAs to mainframes
    단일 프로세서 시스템의 종류는 PDA부터 메인프레임까지 다양함.

- Multiprocessor Systems
다중 프로세서 시스템
    - Two or more CPUs in close Communication
    두 개 이상의 CPU가 밀접하게 통신함.
    - shares the computer bus, clock, memory, and peripheral devices
    컴퓨터 버스, 클럭, 메모리, 주변 장치를 공유함.
    - three main advantages
    세 가지 주요 장점:
        - Increased throughput
        처리량 증가
            - We can expect to get more work done in less time
            더 짧은 시간에 더 많은 작업을 처리할 수 있음.
        - Economy of scale
        규모의 경제
            - can cost less than equivalent multiple single-processor systems
            동등한 다중 단일 프로세서 시스템보다 비용이 적게 들 수 있음.
        - Increased reliablity
        신뢰성 향상
            - The failure of one processor will not halt the system, only slow it down.
            하나의 프로세서가 고장 나더라도 시스템 전체가 멈추지 않고, 단지 속도가 느려질 뿐임.
    - One disadvantage
    하나의 단점
        - Increased complexity
        복잡성 증가
            - They are also more complex in both hardware and software than single processor systems.
            다중 프로세서 시스템은 단일 프로세서 시스템보다 하드웨어와 소프트웨어 양측에서 더 복잡함.
        - Two types of Multiprocessor systems
        다중 프로세서 시스템의 두 가지 유형
            - Asymmetric multiprocessing (AMP)
            비대칭 다중 처리
                - Master-slave relationship of processor
                프로세스 간의 마스터-슬레이브 관계가 존재함.
                - Master processor schedules and allocates work to the slave processors.
                마스터 프로세서가 슬레이브 프로세서에게 작업을 스케줄링하고 할당함.
                - I/O Operations usually are in charge of master processor.
                입출력 작업(I/O)는 일반적으로 마스터 프로세서가 담당함.
            - Symmetric multiprocessing (SMP)
            대칭 다중 처리
                - No master-slave relationship between processors
                프로세서 간에 마스터-슬레이브 관계가 없음.
                - All processors are peer to each otehr
                모든 프로세서가 동등한 관계를 가짐.
                - Each processor performs its own task without interference from others.
                각 프로세서는 다른 프로세서의 간섭 없이 자체 작업을 수행함.

- Clustered System
클러스터 시스템
    - gather multiple systems to accomplish computational work.
    클러스터 시스템은 여러 시스템을 모아 컴퓨팅 작업을 수행함.
    - The multiple systems are interconnected to each otehr via LAN(local area network).
    이 시스들은 LAN(로컬 영역 네트워크)을 통해 서로 연결됨.
    - Examples:
    예시
        - Web server clusters.
        웹 서버 클러스터

![Screenshot 2024-10-09 at 17.05.56.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/43956197-5ede-4f79-b6d4-b1b9b9003395/Screenshot_2024-10-09_at_17.05.56.png)

### Operating System Structure
운영체제 구조

- Multiprogramming needed for efficiency
Multiprogramming은 효율성을 위해 필요함.
    - Single user cannot keep CPU and I/O devices busy at all times
    단일 사용자는 CPU와 I/O 장치를 항상 바쁘게 유지할 수 없음.
    - Multiprogramming organizes jobs (code and data) so CPU always has one to execute
    다중 프로그래밍은 작업(코드와 데이터)을 구성하여 CPU가 항상 실행할 작업을 갖도록 함.
    - A subset of total jobs in system is kept in memory
    시스템의 전체 작업 중 일부는 메모리에 유지됨.
    - One job selected and run via job scheduling
    하나의 작업이 작업 스케쥴링을 통해 선택되어 실행됨.
    - When it has to wait (for I/O for example), OS switches to another job
    작업이 대기 상태가 되면(예: I/O 대기), 운영 체제는 다른 작업으로 전환함.

- Timesharing (multitasking) is logical extension in which CPU switches jobs so frequently that users can interact with each job while it is running, creating interactive computing
Timesharing(multitasking)은 논리적인 확장 개념으로, CPU가 작업을 매우 자주 전환하여 사용자가 각 작업이 실행되는 동안 상호작용할 수 있도록 하여 Interactive Computing을 가능하게 함.
    - Response time should be < 1 second
    응답 시간은 1초 미만이어야 함.
    - Each user has at least one program executing in memory → process
    각 사용자는 최소 하나의 프로그램을 메모리에서 실행하고 있으며, 이를 프로세스라고 함.
    - If several jobs ready to run at the same time → CPU scheduling
    여러 작업이 동시에 실행 준비가 되어 있으면, CPU 스케쥴링이 이루어짐.
    - If processes don’t fit in memory, swapping moves them in and out to run
    프로세스가 메모리에 모두 적재되지 않으면, **스와핑(Swapping)**을 통해 메모리 안팎으로 이동하여 실행됨.
    - Virtual memory allows execution of processes not completely in memory
    가상 메모리는 메모리에 완전히 적재되지 않은 프로세스도 실행할 수 있도록 함.

### Memory Layout for Multiprogrammed System
다중 프로그래밍 시스템의 메모리 레이아웃

- OS keeps several jobs in memory simultaneously.
운영체제는 여러 작업을 동시에 메모리에 유지함.
- Set of jobs in the memory can be a subset of the jobs kept in the job pool.
메모리에 있는 작업 집합은 작업 풀에 저장된 작업의 하위 집합일 수 있음.
- OS picks and begins to execute one of the jobs in memory
운영체제는 메모리에 있는 작업 중 하나를 선택하여 실행을 시작함.

- In I/O operation of a job, OS switches to another job to execute.
작업이 I/O 작업을 수행하는 동안, 운영 체제는 다른 작업으로 전환하여 실행함.
- When the job needs to wait, the CPU is switched to another job, and so on.
작업이 대기 상태가 되면, CPU는 다른 작업으로 전환되고, 이러한 과정이 반복됨.

![Screenshot 2024-10-09 at 17.30.02.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/45cc67a8-d31b-4e2c-9ed6-2355318ba7f3/Screenshot_2024-10-09_at_17.30.02.png)

### Operating-System Operations
운영체제의 작동

- Modern OS are Intrrupt driven by hardware.
현대의 운영체제는 하드웨어에 의해 인터럽트 구동 방식으로 작동함.
- Software error or request creates exception or trap
소프트웨어 오류나 요청은 예외 또는 트랩을 생성함.
    - Division by zero, request for operating system service
    0으로 나누기, 운영체제 서비스 요청.
    - Other process problems include infinite loop, processes modifying each other or the operating system
    기타 프로세스 문제로는 무한 루프, 프로세스가 서로 또는 운영체제를 수정하는 경우 등이 있음.

- Dual-mode operation allows OS to protect itself and other system components
이중 모드 작업은 운영체제가 스스로와 다른 시스템 구성 요소를 보호할 수 있도록 함.
    - User mode
    사용자 모드
    - Kernel mode (called supervisor mode, system mode, privileged mode)
    커널 모드 (감독 모드, 시스템 모드, 특권 모드라고도 불림).
    - Mode bit provided by hardware
    하드웨어에 의해 모드 비트가 제공됨.
        - Provides ability to distinguish when system is running user code or kernel code
        시스템이 사용자 코드 또는 커널 코드를 실행 중인지 구별할 수 있는 기능을 제공함.
        - Some instructions designated as privileged, only executable in kernel mode
        일부 명령은 특권 명령으로 지정되며, 오직 커널 모드에서만 실행 가능함.
        - System call changes mode to kernel, return from call resets it to user
        시스템 호출은 모드를 커널 모드로 변경하며, 호출이 끝나면 사용자 모드로 재설정됨.

### Transition from User to Kernel Mode
사용자 모드에서 커널 모드로의 전환

- At system boot time, the hardware starts in kernel mode
시스템 부팅 시, 하드웨어는 커널 모드에서 시작함.
- The OS is then loaded and starts user applications in user mode
이후 운영체제가 로드되고 사용자 애플리케이션을 사용자 모드에서 실행하기 시작함.
- Whenever a trap or interrupt occurs, the hardware switches from user mode to kernel mode (mode bit = 0)
트랩 또는 인터럽트가 발생할 때마다, 하드웨어는 사용자 모드에서 커널 모드로 전환됨 (모드 비트 = 0).
- Whenever the OS gains control of the computer it is kernel mode.
운영 체제가 컴퓨터의 제어를 획득할 때는 항상 커널 모드임.
- The system always switches to user mode before passing control to a user program. (mode bit = 1)
시스템은 사용자 프로그램에 제어를 넘기기 전에 항상 사용자 모드로 전환됨 (모드 비트 = 1).

![Screenshot 2024-10-09 at 17.37.41.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/18ba0db5-6645-4559-82b3-63e961f1c20e/Screenshot_2024-10-09_at_17.37.41.png)

### Timer - 일정한 간격으로 Interrupt 발생
타미어

- The OS maintains control over the CPU
운영체제는 CPU에 대한 제어를 유지함.
- The OS must prevent a user program from
운영체제는 사용자 프로그램이 다음을 하지 않도록 방지해야 함:
    - getting stuck in an infinite loop
    무한 루프에 빠지지 않도록.
    - not calling system services
    시스템 서비스를 호출하지 않고 독점적으로 자원을 사용하지 않도록.
    - never returning control to the OS
    운영체제에 제어를 반환하지 않는 상황을 방지함.

- Timer to prevent infinite loop / process hogging resources
무한 루프 또는 프로세스가 자원을 독점하는 상황을 방지하기 위해 타이머를 사용함.
    - Set interrupt after specific period (fixed timer)
    특정 기간 후에 인터럽트를 발생시키는 고정 타이머 설정.
    - Operating system decrements counter (variable timer)
    운영 체제는 변동 타이머에서 카운터를 감소시킴.
        - When counter zero generate an interrupt
        카운터가 0이 되면 인터럽트가 발생함.

- Before turning over control to the user, the OS ensures that the timer is set to interrupt
사용자에게 제어를 넘기기 전에 운영 체제는 타이머가 인터럽트를 발생시키도록 설정을 보장함.
    - If the timer interrupts, control transfers automatically to the OS.
    타이머가 인터럽트를 발생시키면, 제어는 자동으로 운영체제로 전환됨.

### Process Management
프로세스 관리

- A process is a program in execution. It is a unit of work within the system.
프로세스는 실행 중인 프로그램으로, 시스템 내에서 작업 단위를 의미함.
    - Program is a passive entity, process is an active entity.
    프로그램은 수동적인 엔티티이고, 프로세스는 능동적인 엔티티임.
- Process needs resources to accomplish its task
프로세스는 작업을 완료하기 위해 자원이 필요함.
    - CPU, memory, I/O, files
    - Initialization data
    초기화 데이터
- Process termination requires release of any reusable resources
프로세스가 종료되면, 재사용 가능한 자원을 해제해야 함.

- Single-threaded process has one program counter specifying location of next instruction to execute
단일 스레드 프로세스는 다음에 실행할 명령의 위치를 지정하는 하나의 프로그램 카운터를 가짐.
    - Process executes instructions sequentiall,y one at a time, until completion
    프로세스는 명령을 순차적으로 하나씩 실행하며 완료될 때까지 진행함.
- Multi-threaded process has one program counter per thread
멀티스레드 프로세스는 각 스레드마다 하나의 프로그램 카운터를 가짐.

- Typically, system has many processes, some users, some operating system running concurrently on one or more CPUs
일반적으로 시스템에는 많은 프로세스가 있으며, 일부는 사용자 프로세스이고 일부는 운영체제가 하나 이상의 CPU에서 동시에 실행됨.
    - Concurrency by multiplexing the CPUs among the processes / threads
    CPU는 프로세스/스레드 간의 멀티플렉싱을 통해 동시성을 제공함.

### Process Management Activities
프로세스 관리 활동

The operating system is responsible for the following activities in connection with process management:
운영체제는 프로세스 관리와 관련하여 다음과 같은 활동을 수행할 책임이 있습니다:

- Creating and deleting both user and system processes
사용자 및 시스템 프로세스의 생성 및 삭제.
- Suspending and resuming processes
프로세스의 일시 중단 및 재개.
- Providing mechanisms for process synchronization
프로세스 동기화를 위한 메커니즘 제공.
- Providing mechanisms for process communication
프로세스 간 통신을 위한 메커니즘 제공.
- Providing mechanisms for deadlock handling
교착 상태 처리를 위한 메커니즘 제공.

### Memory Management
메모리 관리

- All data in memory before and after processing
모든 데이터는 처리 전후에 메모리에 저장됨.
- All instructions in memory in order to execute
모든 명령어는 실행을 위해 메모리에 있어야 함.

- Memory management determines what is in memory when
메모리 관리는 어떤 데이터가 언제 메모리에 있어야 하는지를 결정함.
    - Optimizing CPU utilization and computer response to users
    CPU 사용률과 사용자에 대한 컴퓨터 응답 시간을 최적화함.

- Memory management activities
메모리 관리 활동
    - Keeping track of which parts of memory are currently being used and by whom
    현재 메모리의 어느 부분이 사용 중인지, 그리고 누가 사용 중인지를 추적.
    - Deciding which processes (or parts thereof) and data to move into and out of memory
    어떤 프로세스(또는 그 일부분)와 데이터를 메모리에 넣고 빼야 할지 결정.
    - Allocating and de-allocating memory space as needed
    필요에 따라 메모리 공간을 할당하고 해제.

### Storage Management
저장 관리

- OS provides uniform, logical view of information storage
운영체제는 정보 저장소에 대한 일관된 논리적 뷰를 제공함.
    - abstracts physical properties to logical storage unit - file & dir
    물리적 속성을 추상화하여 논리적 저장 단위인 파일과 디렉터리로 표현함.
    - Each medium is controlled by device driver
    각 저장 매체는 장치 드라이버에 의해 제어됨.
        - i.e., disk driver, tape driver
        예 : 디스크 드라이버, 테이프 드라이버.
        - Varying properties include access speed, capacity, data-transfer rate, access method (sequential or random)
        속성에는 접근 속도, 용량, 데이터 전송 속도, 접근 방식(순차적 또는 랜덤)이 포함됨.

- File-System management
파일 시스템 관리
    - Files usually organized into directories
    파일은 일반적으로 디렉터리로 구성됨.
    - Access control on most systems to determine who can access what
    대부분의 시스템은 누가 무엇을 접근할 수 있는지 접근 제어를 제공함.
    - OS activities include
    운영체제의 활동에는 다음이 포함됨
        - Creating and deleting files and directories
        파일과 디렉터리의 생성 및 삭제.
        - Primitives to manipulate files and dirs (dir, type, copy, rename)
        파일과 디렉터리를 조작할 수 있는 원시 기능 제공 (디렉터리 조회, 파일 유형, 복사, 이름 변경 등).
        - Mapping files onto secondary storage
        파일을 보조 저장 장치에 매핑.
        - Backup files onto stable (non-volatile) storage media
        파일을 안정적인 비휘발성 저장 매체로 백업.

### Mass-Storage Management
대용량 저장 장치 관리

- Usually, disks used to store data that does not fit in main memory or data that must be kept for a “long” period of time. (secondary storage)
일반적으로 디스크는 주 메모리에 맞지 않는 데이터나 오랜 기간 저장해야 하는 데이터를 보관하는 데 사용됨. (보조 저장 장치)
- Proper management is of central importance, because
    - Entire speed of computer operation hinges on disk subsystem and its algorithms
    
    디스크 서브시스템과 그 알고리즘이 컴퓨터의 전체 속도에 영향을 미치기 때문에, 올바른 관리가 매우 중요함.
    

- OS activities
운영체제의 활동
    - Free-space management
    여유 공간 관리
    - Storage allocation
    저장 공간 할당
    - Disk scheduling
    디스크 스케쥴링

- Some storage need not be fast
일부 저장 장치는 빠를 필요가 없음.
    - Tertiary storage includes optical storage (CD, DVD), magnetic tape
    3차 저장 장치에는 광학 저장 장치(CD, DVD), 자기 테이프 등이 포함됨.
    - Still must be managed
    여전히 관리되어야 함.
    - Varies between WORM (write-once, read-many-times) and RW (read-write)
    WORM(한 번 쓰고 여러 번 읽기)과 RW(읽기-쓰기 가능) 저장 장치 간의 차이 존재.

### I/O Subsystem
I/O 서브시스템

- One purpose of OS is to hide peculiarities of hardware devices from the user
운영체제의 목적 중 하나는 하드웨어 장치의 특이성을 사용자로부터 숨기는 것임.
    - Providing general device-driver interface
    일반적인 장치 드라이버 인터페이스 제공
    - Providing drivers for specific hardware devices
    특정 하드웨어 장치를 위한 드라이버 제공

- I/O subsystem responsible for
I/O 서브시스템의 책임
    - Memory management of I/O including
    I/O의 메모리 관리, 아래의 것을 포함:
        - buffering (storing data temporarily while it is being transferred),
        버퍼링 : 데이터가 전송되는 동안 임시로 데이터를 저장함.
        - caching (storing parts of data in faster storage for performance),
        캐싱 : 성능을 위해 일부 데이터를 더 빠른 저장소에 저장함.
        - spooling (the overlapping of output of one job with input of other jobs)
        스풀링 : 한 작업의 출력과 다른 작업의 입력을 겹쳐서 처리함.

### Protection and Security
보호와 보안

- Protection - any mechanism for controlling access of processes or users to resources defined by the OS
보호 : 운영체제에서 정의한 자원에 대해 프로세스나 사용자의 접근을 제어하는 모든 메커니즘.
- Security - defense of the system against internal and external attacks
보안 : 시스템을 내부 및 외부 공격으로부터 방어하는 것.
    - Huge range, including denial-of-service, worms, viruses, identity theft, theft of service
    공격 범위는 서비스 거부 공격, 웜, 바이러스, 신원 도용, 서비스 도용 등을 포함.

- Security systems generally first distinguish among users, to determine who can do what
보안 시스템은 일반적으로 사용자 구별부터 시작하여, 각 사용자가 어떤 작업을 수행할 수 있는지를 결정함
    - User identities (user IDs, security IDs) include name and associated number, one per user
    사용자 식별자는 사용자별로 이름과 관련 번호를 포함함.
    - User ID then associated with all files, processes of that user to determine access control
    사용자 ID는 해당 사용자의 모든 파일과 프로세스에 연결되어 접근 제어를 결정함.
    - Group identifier (group ID) allows set of users to be defined and managed, then also associated with each process, file
    그룹 식별자는 사용자 그룹을 정의하고 관리하며, 각 프로세스와 파일에도 연결됨.

### Summary
요약

- Three main goals of OS
운영체제의 세 가지 주요 목표
    - Process Management, Environment Management, Resource Management
    프로세스 관리, 환경 관리, 자원 관리
- Four components of Computer System
컴퓨터 시스템의 네 가지 구성 요소
    - Hardware, OS, program, user
    하드웨어, 운영체제, 프로그램, 사용자
- OS is interrupt driven.
운영체제는 인터럽트 구동 방식으로 작동함.
    - Interrupt is a request signal from hardware and software to OS.
    인터럽트는 하드웨어 또는 소프퉤어에서 운영체제로 보내는 요청 신호임.
    - Interrupt transfers control to the interrupt service routine
    인터럽트는 인터럽트 서비스 루틴으로 제어를 전송함.
- I/O is data transfer in between devices and local buffer
I/O는 장치와 로컬 버퍼 간의 데이터 전송임.
    - device controller and device driver are involved.
    장치 컨트롤러와 장치 드라이버가 관여함.
    - Synchronous I/O vs. Asynchronous I/O
    동기식 I/O vs 비동기식 I/O
- Computer system has a hierarchical storage structure.
컴퓨터 시스템은 계층적인 저장 구조를 가짐.
    - Register, Cache, Memory, Secondary storage, Tertiary storage
    레지스터, 캐시, 메모리, 보조 저장 장치, 3차 저장 장치.
- OS provides multitasking environment which creates interactive computing.
운영체제는 멀티태스킹 환경을 제공하여 대화형 컴퓨팅을 가능하게 함.
- Dual-mode operation allows OS to protect itself and other system components
이중 모드 작업을 통해 운영 체제는 스스로와 다른 시스템 구성 요소를 보호할 수 있음.
    - User mode, Kernel mode
    사용자 모드, 커널 모드
- OS provides protection and security mechanism.
운영체제는 보호 및 보안 메커니즘을 제공함.

- Chapter 0, Chapter 1 | 첫 번째 O/X 퀴즈
    
    
    **문제**
    
    1.	운영체제는 컴퓨터 하드웨어와 사용자 사이의 중재자 역할을 한다. O
    
    2.	운영체제의 주요 목표 중 하나는 컴퓨터 하드웨어를 효율적으로 사용하는 것이다. O
    
    3.	프로세스는 실행 중인 프로그램으로, 시스템 내에서 작업의 단위이다. O
    
    4.	멀티프로그래밍은 단일 사용자가 CPU와 I/O 장치를 항상 바쁘게 유지하는 것을 의미한다. O
    
    5.	타이머는 운영체제가 프로세스가 무한 루프에 빠지는 것을 방지하는 데 사용된다. O
    
    6.	캐싱은 느린 저장소에서 더 빠른 저장소로 정보를 복사하는 것을 의미한다. X
    
    7.	캐시 크기는 캐싱되는 저장소보다 크다. X
    
    8.	비동기식 I/O에서는 I/O 작업이 완료될 때까지 프로세스가 대기한다. X
    
    9.	커널 모드에서는 모든 명령어를 실행할 수 있다. O
    
    10.	사용자 모드에서 특권 명령어를 실행할 수 있다. X
    
    11.	인터럽트는 하드웨어 또는 소프트웨어로부터 운영체제로 보내는 요청 신호이다. O
    
    12.	시스템 호출은 소프트웨어 인터럽트를 발생시킨다. ?
    
    13.	DMA는 CPU의 개입 없이 데이터 전송을 수행한다. ?
    
    14.	멀티프로세서 시스템은 단일 프로세서 시스템보다 항상 더 복잡하지 않다. X
    
    15.	대칭 다중 처리(SMP)에서는 프로세서 간에 마스터-슬레이브 관계가 존재한다. ?
    
    16.	운영체제는 인터럽트 구동 방식으로 작동한다. O
    
    17.	스와핑은 메모리에 프로세스를 적재하고 제거하는 것을 의미한다. ?
    
    18.	가상 메모리는 메모리에 완전히 적재되지 않은 프로세스도 실행할 수 있게 한다. O
    
    19.	사용자 프로세스는 비동기식 I/O를 사용한다. O
    
    20.	운영체제는 동기식 I/O를 사용한다. O
    
    21.	장치 드라이버는 각 장치 컨트롤러에 대해 운영체제에 의해 제공된다. O
    
    22.	파일 시스템 관리는 파일과 디렉터리의 생성 및 삭제를 포함한다. O
    
    23.	보호 메커니즘은 프로세스나 사용자의 자원 접근을 제어하는 것이다. O
    
    24.	보안은 시스템을 내부 및 외부 공격으로부터 방어하는 것을 의미한다. O
    
    25.	운영체제는 멀티태스킹 환경을 제공하여 대화형 컴퓨팅을 가능하게 한다. O
    
    26.	모드 비트는 하드웨어에 의해 제공되며, 시스템이 사용자 코드 또는 커널 코드를 실행 중인지 구별할 수 있게 한다. O
    
    27.	멀티스레드 프로세스는 각 스레드마다 하나의 프로그램 카운터를 가진다. O
    
    28.	캐시는 캐싱되는 저장소보다 작다. X
    
    29.	클러스터 시스템은 여러 시스템을 모아 컴퓨팅 작업을 수행한다. O
    
    30.	프로세스 관리 활동에는 프로세스 간 통신을 위한 메커니즘 제공이 포함된다. O
    
    31.	타이머는 일정한 간격으로 인터럽트를 발생시킨다. O
    
    32.	비대칭 다중 처리(AMP)에서는 모든 프로세서가 동등한 관계를 가진다. X
    
    33.	운영체제는 사용자로부터 하드웨어 장치의 특이성을 숨기는 역할을 한다. O
    
    34.	인터럽트 서비스 루틴은 인터럽트 벡터 테이블에 의해 호출된다. ?
    
    35.	스풀링은 한 작업의 출력과 다른 작업의 입력을 겹쳐서 처리하는 것을 의미한다. ?
    
    36.	캐시 일관성은 멀티프로세서 환경에서 중요하다. O
    
    37.	가상 메모리는 프로세스의 메모리 사용량을 제한한다. X
    
    38.	I/O 서브시스템은 버퍼링, 캐싱, 스풀링을 포함한 메모리 관리를 담당한다. ?
    
    39.	운영체제는 프로세스의 생성과 삭제만을 담당한다. X
    
    40.	보호와 보안은 운영체제의 동일한 개념이다. X
    
    41.	대용량 저장 장치 관리는 디스크 스케줄링을 포함한다. O
    
    42.	프로세스는 수동적인 엔티티이고, 프로그램은 능동적인 엔티티이다. X
    
    43.	운영체제는 프로세스 동기화를 위한 메커니즘을 제공한다. O
    
    44.	시스템 콜은 사용자 모드에서 실행된다. O
    
    45.	인터럽트 발생 시, 하드웨어는 사용자 모드에서 커널 모드로 전환된다. O
    
    46.	모드 비트가 1이면 커널 모드이다. O
    
    47.	캐싱은 컴퓨터의 여러 레벨에서 수행되는 중요한 원칙이다. O
    
    48.	클러스터 시스템은 웹 서버 클러스터의 예시가 있다. O
    
    49.	가상 메모리는 물리적 메모리보다 큰 프로그램을 실행할 수 있게 한다. O
    
    50.	운영체제는 사용자 프로그램이 시스템 자원을 독점하지 않도록 타이머를 사용한다. O
    
- Chapter 0, Chapter 1 | 첫 번째 O/X 퀴즈 정답 및 해설
    
    1.	**O** (운영체제는 컴퓨터 하드웨어와 사용자 사이에서 중재자 역할을 합니다. 이는 사용자와 하드웨어 간의 원활한 상호 작용을 가능하게 합니다.)
    
    2.	**O** (운영체제의 주요 목표 중 하나는 하드웨어를 효율적으로 사용하는 것입니다. 이는 자원 관리의 중요한 부분입니다.)
    
    3.	**O** (프로세스는 실행 중인 프로그램으로, 시스템 내에서 작업 단위입니다. 프로그램이 수동적이라면 프로세스는 능동적입니다.)
    
    4.	**X** (멀티프로그래밍은 여러 사용자의 작업을 메모리에 보관하여 CPU와 I/O 장치를 항상 바쁘게 유지하는 것을 의미합니다. 단일 사용자가 아닙니다.)
    
    5.	**O** (타이머는 운영체제가 프로세스가 무한 루프에 빠지는 것을 방지하는 데 사용됩니다. 이는 시스템 자원의 독점을 막기 위함입니다.)
    
    6.	**O** (캐싱은 느린 저장소에서 더 빠른 저장소로 정보를 복사하는 것을 의미합니다. 이는 시스템의 성능 향상을 위해 중요합니다.)
    
    7.	**X** (캐시 크기는 캐싱되는 저장소보다 작습니다. 그렇기 때문에 어떤 데이터를 캐시에 저장할지 결정하는 것이 중요합니다.)
    
    8.	**X** (비동기식 I/O에서는 I/O 작업이 완료될 때까지 프로세스가 대기하지 않고 다른 작업을 수행합니다. 동기식 I/O에서 프로세스가 대기합니다.)
    
    9.	**O** (커널 모드에서는 모든 명령어, 특히 특권 명령어를 실행할 수 있습니다. 이는 시스템의 핵심 기능을 수행하기 위해 필요합니다.)
    
    10.	**X** (사용자 모드에서는 특권 명령어를 실행할 수 없습니다. 이는 시스템의 안정성과 보안을 위해 제한됩니다.)
    
    11.	**O** (인터럽트는 하드웨어 또는 소프트웨어로부터 운영체제로 보내는 요청 신호입니다. 이는 이벤트의 발생을 알리는 메커니즘입니다.)
    
    12.	**O** (시스템 호출은 소프트웨어 인터럽트를 발생시킵니다. 이를 통해 사용자 프로세스가 운영체제의 서비스를 요청할 수 있습니다.)
    
    13.	**O** (DMA는 CPU의 개입 없이 데이터 전송을 수행합니다. 이는 고속의 I/O 장치에서 효율적인 데이터 전송을 가능하게 합니다.)
    
    14.	**X** (멀티프로세서 시스템은 단일 프로세서 시스템보다 하드웨어와 소프트웨어 측면에서 더 복잡합니다. 이는 여러 프로세서 간의 조율이 필요하기 때문입니다.)
    
    15.	**X** (대칭 다중 처리(SMP)에서는 프로세서 간에 마스터-슬레이브 관계가 없으며, 모두 동등합니다. 마스터-슬레이브 관계는 비대칭 다중 처리에서 나타납니다.)
    
    16.	**O** (운영체제는 인터럽트 구동 방식으로 작동합니다. 이는 이벤트 기반의 처리 방식을 의미합니다.)
    
    17.	**O** (스와핑은 메모리에 프로세스를 적재하고 제거하는 것을 의미합니다. 이는 메모리 관리의 한 방법입니다.)
    
    18.	**O** (가상 메모리는 메모리에 완전히 적재되지 않은 프로세스도 실행할 수 있게 합니다. 이는 메모리의 효율적인 사용을 가능하게 합니다.)
    
    19.	**X** (사용자 프로세스는 동기식 I/O를 사용합니다. I/O 작업이 완료될 때까지 대기합니다.)
    
    20.	**X** (운영체제는 비동기식 I/O를 사용합니다. I/O 작업을 요청한 후 다른 작업을 수행합니다.)
    
    21.	**O** (장치 드라이버는 각 장치 컨트롤러에 대해 운영체제에 의해 제공됩니다. 이는 장치와 운영체제 간의 인터페이스를 제공합니다.)
    
    22.	**O** (파일 시스템 관리는 파일과 디렉터리의 생성 및 삭제를 포함합니다. 이는 데이터 관리의 기본입니다.)
    
    23.	**O** (보호 메커니즘은 프로세스나 사용자의 자원 접근을 제어하는 것입니다. 이는 시스템의 안정성과 보안을 유지합니다.)
    
    24.	**O** (보안은 시스템을 내부 및 외부 공격으로부터 방어하는 것을 의미합니다. 이는 시스템의 신뢰성을 높입니다.)
    
    25.	**O** (운영체제는 멀티태스킹 환경을 제공하여 대화형 컴퓨팅을 가능하게 합니다. 이는 사용자 경험을 향상시킵니다.)
    
    26.	**O** (모드 비트는 하드웨어에 의해 제공되며, 시스템이 사용자 코드 또는 커널 코드를 실행 중인지 구별할 수 있게 합니다. 이는 모드 전환에 사용됩니다.)
    
    27.	**O** (멀티스레드 프로세스는 각 스레드마다 하나의 프로그램 카운터를 가집니다. 이는 각 스레드가 독립적으로 실행될 수 있게 합니다.)
    
    28.	**O** (캐시는 캐싱되는 저장소보다 작습니다. 그렇기 때문에 효율적인 캐시 관리가 필요합니다.)
    
    29.	**O** (클러스터 시스템은 여러 시스템을 모아 컴퓨팅 작업을 수행합니다. 이는 처리 능력을 향상시킵니다.)
    
    30.	**O** (프로세스 관리 활동에는 프로세스 간 통신을 위한 메커니즘 제공이 포함됩니다. 이는 프로세스 협업에 필수적입니다.)
    
    31.	**O** (타이머는 일정한 간격으로 인터럽트를 발생시킵니다. 이는 운영체제가 시스템 자원을 제어하는 데 사용됩니다.)
    
    32.	**X** (비대칭 다중 처리(AMP)에서는 프로세서 간에 마스터-슬레이브 관계가 있습니다. 모든 프로세서가 동등한 관계인 것은 SMP입니다.)
    
    33.	**O** (운영체제는 사용자로부터 하드웨어 장치의 특이성을 숨기는 역할을 합니다. 이는 사용자에게 일관된 인터페이스를 제공합니다.)
    
    34.	**O** (인터럽트 서비스 루틴은 인터럽트 벡터 테이블에 의해 호출됩니다. 이는 다양한 인터럽트에 대응하기 위해 사용됩니다.)
    
    35.	**O** (스풀링은 한 작업의 출력과 다른 작업의 입력을 겹쳐서 처리하는 것을 의미합니다. 이는 시스템 효율성을 높입니다.)
    
    36.	**O** (캐시 일관성은 멀티프로세서 환경에서 중요합니다. 이는 각 프로세서가 최신 데이터를 유지하도록 합니다.)
    
    37.	**X** (가상 메모리는 프로세스의 메모리 사용량을 제한하지 않고, 오히려 메모리에 완전히 적재되지 않은 프로세스도 실행할 수 있게 합니다.)
    
    38.	**O** (I/O 서브시스템은 버퍼링, 캐싱, 스풀링을 포함한 메모리 관리를 담당합니다. 이는 I/O 효율성을 높입니다.)
    
    39.	**X** (운영체제는 프로세스의 생성과 삭제뿐만 아니라 동기화, 통신, 스케줄링 등 다양한 프로세스 관리 활동을 담당합니다.)
    
    40.	**X** (보호와 보안은 운영체제의 관련된 개념이지만, 보호는 자원 접근 제어를 의미하고, 보안은 시스템을 공격으로부터 방어하는 것을 의미합니다.)
    
    41.	**O** (대용량 저장 장치 관리는 디스크 스케줄링을 포함합니다. 이는 저장 장치의 효율적인 사용을 돕습니다.)
    
    42.	**X** (프로세스는 능동적인 엔티티이고, 프로그램은 수동적인 엔티티입니다. 프로세스는 실행 중인 프로그램입니다.)
    
    43.	**O** (운영체제는 프로세스 동기화를 위한 메커니즘을 제공합니다. 이는 데이터 일관성을 유지합니다.)
    
    44.	**X** (시스템 콜은 사용자 모드에서 커널 모드로 전환되어 실행됩니다. 이는 운영체제의 서비스를 요청하기 때문입니다.)
    
    45.	**O** (인터럽트 발생 시, 하드웨어는 사용자 모드에서 커널 모드로 전환됩니다. 이는 운영체제가 인터럽트를 처리하기 위해 필요합니다.)
    
    46.	**X** (모드 비트가 0이면 커널 모드입니다. 모드 비트가 1이면 사용자 모드입니다.)
    
    47.	**O** (캐싱은 컴퓨터의 여러 레벨에서 수행되는 중요한 원칙입니다. 이는 시스템 전반의 성능을 향상시킵니다.)
    
    48.	**O** (클러스터 시스템의 예로 웹 서버 클러스터가 있습니다. 이는 웹 서비스의 처리량을 높입니다.)
    
    49.	**O** (가상 메모리는 물리적 메모리보다 큰 프로그램을 실행할 수 있게 합니다. 이는 프로그램의 유연성을 높입니다.)
    
    50.	**O** (운영체제는 사용자 프로그램이 시스템 자원을 독점하지 않도록 타이머를 사용합니다. 이는 공정한 자원 분배를 위해 필요합니다.)
    
- Chapter 0, Chapter 1 | 첫 번째 O/X 퀴즈 채점 및 틀린 문제 해설
    
    
    채점 결과를 알려드리겠습니다.
    
    총 **50문제** 중에서 **36문제**를 맞추셨습니다.
    
    **틀린 문제는 다음과 같습니다:**
    
    1.	**문제 4**: **귀하의 답변**: O / **정답**: **X**
    
    •	**해설**: 멀티프로그래밍은 **여러 사용자의 작업**을 메모리에 보관하여 CPU와 I/O 장치를 항상 바쁘게 유지하는 것을 의미합니다. **단일 사용자가 아닙니다**.
    
    2.	**문제 6**: **귀하의 답변**: X / **정답**: **O**
    
    •	**해설**: **캐싱은 느린 저장소에서 더 빠른 저장소로 정보를 복사하는 것**을 의미합니다. 이는 시스템의 성능 향상을 위해 중요한 개념입니다.
    
    3.	**문제 12**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **시스템 호출은 소프트웨어 인터럽트를 발생시킵니다**. 이를 통해 사용자 프로세스가 운영체제의 서비스를 요청할 수 있습니다.
    
    4.	**문제 13**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **DMA(Direct Memory Access)**는 **CPU의 개입 없이 데이터 전송을 수행**합니다. 이는 고속의 I/O 장치에서 효율적인 데이터 전송을 가능하게 합니다.
    
    5.	**문제 15**: **귀하의 답변**: ? / **정답**: **X**
    
    •	**해설**: **대칭 다중 처리(SMP)**에서는 프로세서 간에 **마스터-슬레이브 관계가 없으며**, 모든 프로세서가 동등합니다. 마스터-슬레이브 관계는 **비대칭 다중 처리(AMP)**에서 나타납니다.
    
    6.	**문제 17**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **스와핑은 메모리에 프로세스를 적재하고 제거하는 것**을 의미합니다. 이는 메모리 관리의 한 방법으로, 프로세스들을 메모리에 올렸다 내렸다 하며 메모리 공간을 효율적으로 사용합니다.
    
    7.	**문제 19**: **귀하의 답변**: O / **정답**: **X**
    
    •	**해설**: **사용자 프로세스는 동기식 I/O를 사용**합니다. I/O 작업이 완료될 때까지 프로세스가 대기합니다. 비동기식 I/O는 **운영체제**가 사용합니다.
    
    8.	**문제 20**: **귀하의 답변**: O / **정답**: **X**
    
    •	**해설**: **운영체제는 비동기식 I/O를 사용**합니다. I/O 작업을 시작한 후 다른 작업을 수행하여 시스템 효율을 높입니다.
    
    9.	**문제 28**: **귀하의 답변**: X / **정답**: **O**
    
    •	**해설**: **캐시는 캐싱되는 저장소보다 작습니다**. 그렇기 때문에 어떤 데이터를 캐시에 저장할지 결정하는 **캐시 관리**가 중요합니다.
    
    10.	**문제 34**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **인터럽트 서비스 루틴은 인터럽트 벡터 테이블에 의해 호출**됩니다. 인터럽트 벡터 테이블은 다양한 인터럽트에 대응하는 서비스 루틴의 주소를 저장하고 있습니다.
    
    11.	**문제 35**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **스풀링은 한 작업의 출력과 다른 작업의 입력을 겹쳐서 처리**하는 것을 의미합니다. 이는 시스템 자원의 효율적인 사용을 위한 기법입니다.
    
    12.	**문제 38**: **귀하의 답변**: ? / **정답**: **O**
    
    •	**해설**: **I/O 서브시스템은 버퍼링, 캐싱, 스풀링을 포함한 메모리 관리**를 담당합니다. 이는 I/O 효율성을 높이고 데이터의 일관성을 유지하기 위해 필요합니다.
    
    13.	**문제 44**: **귀하의 답변**: O / **정답**: **X**
    
    •	**해설**: **시스템 콜은 사용자 모드에서 실행되지 않고**, **커널 모드에서 실행**됩니다. 시스템 콜을 호출하면 모드가 사용자 모드에서 커널 모드로 전환됩니다.
    
    14.	**문제 46**: **귀하의 답변**: O / **정답**: **X**
    
    •	**해설**: **모드 비트가 0이면 커널 모드**이고, **모드 비트가 1이면 사용자 모드**입니다. 따라서 모드 비트가 1이면 사용자 모드입니다.
    
    **전체 요약:**
    
    •	**총 문제 수**: 50문제
    
    •	**맞은 문제 수**: 36문제
    
    •	**틀린 문제 수**: 14문제