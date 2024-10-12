# Chapter 2: Operating-System Structures

## Chapter 2: Operating-System Structures

- Operating System Services
- User Operating System Interface
- System Calls
- Types of System Calls
- System Programs

- Operating System Design and Implementation
- Operating System Structure
- Virtual Machines

## Objectives

- To describe the services an operating system provides to users, processes, and other systems
- To discuss the various ways of structuring an operating system

**To whom:** Users, Processes, other systems

## Operating System Services

**With What:** CPU, Storage, I/O Devices

- One set of OS services provides functions that are helpful to the user
- Another set of OS functions exists for ensuring the efficient operation of the system itself via resource sharing

### Functions Helpful to User

- **User Interface**
  - Almost all operating systems have a user interface (UI)
  - Varies between Command-Line Interface (CLI), Graphical User Interface (GUI), Batch Interface

- **Program Execution**
  - The OS must be able to load a program into memory and to run that program, and execution either normally or abnormally (indicating error)
  - 운영 체제는 프로그램을 메모리에 로드하고 해당 프로그램을 실행할 수 있어야 하며, 실행은 정상적으로 또는 비정상적으로(오류를 나타내는 방식으로) 이루어져야 합니다.

- **I/O Operations**
  - A running program may require I/O, which may involve a file or an I/O device.

- **File-system Manipulation**
  - The file system is of particular interest.
  - Processes need to:
    - Read and write files and directories
    - Create and delete them
    - Search them
    - List file information
  - Permission management is also required.

- **Communications**
  - Processes may exchange information, on the same computer or between computers over a network
  - Communications may be via shared memory or through message passing (packets moved by the OS)
  - 통신은 공유 메모리 또는 메시지 전달(운영체제가 이동하는 패킷)을 통해 이루어질 수 있습니다.

- **Error Detection**
  - OS needs to be constantly aware of possible errors
    - May occur in the CPU and memory, in I/O devices, in user programs
  - For each type of error, OS should take the appropriate action to ensure correct and consistent computing
    - 각 유형의 오류에 대해 운영체제는 올바르고 일관된 컴퓨팅을 보장하기 위해 적절한 조치를 취해야 합니다.
  - Debugging facilities can greatly enhance the user’s and programmer’s abilities to efficiently use the system
    - 디버깅 기능은 사용자와 프로그래머가 시스템을 효율적으로 사용할 수 있는 능력을 크게 향상시킬 수 있습니다.

### Functions Ensuring Efficient Operation via Resource Sharing

- **Resource Allocation**
  - When multiple users or multiple jobs are running concurrently, resources must be allocated to each of them
  - Many types of resources:
    - Some (such as CPU cycles, main memory, and file storage) may have special allocation code.
    - Others (such as I/O devices) may have general request and release code.

- **Accounting**
  - To keep track of which users use how much and what kinds of computer resources

- **Protection and Security in a Multi-user Computer System**
  - The owners of information may want to control the use of that information
  - Concurrent processes should not interfere with each other
    - 동시 실행되는 프로세스는 서로 간섭하지 않아야 합니다.
  - Protection involves ensuring that all access to system resources is controlled
    - 보호는 시스템 자원에 대한 모든 접근이 통제되도록 보장하는 것을 포함합니다.
  - Security of the system from outsider attacks requires user authentication
    - 외부 공격으로부터 시스템의 보안을 위해 사용자 인증이 필요합니다.
    - Extends to defending external I/O devices from invalid access attempts
      - 외부 I/O 장치를 무효한 접근 시도로부터 방어하는 것까지 확장됩니다.

## User Operating System Interface

- Two fundamental approaches for users to interface with the operating system

### Command-Line Interface (CLI)

- Provides a command interpreter
- Allows users to directly enter commands that are to be performed by the operating system
- 사용자가 운영체제가 수행할 명령을 직접 입력할 수 있도록 합니다.

### Graphical User Interface (GUI)

- Allows users to interface with the OS via GUI

## User Operating System Interface - CLI

- **CLI allows direct command entry**
  - Command Line Interface (CLI)
  - Sometimes implemented in the kernel,
    - 때로는 커널에 구현되며,
  - Sometimes by systems program
    - 때로는 시스템 프로그램에 의해 구현됩니다
  - Sometimes multiple flavors are implemented - shells
    - 때로는 여러 가지 버전이 구현됩니다 - 쉘
    - Examples:
      - BASH (Bourne-Again SHell), CSH (C Shell), KSH (Korn SHell), TCSH on Linux
      - CMD on Windows OS (XP, Vista, 7, 10)
  - Primarily fetches a command from user and executes it
    - 주로 사용자로부터 명령을 받아 실행합니다
    - Sometimes commands are built-in,
      - 때로는 명령이 내장되어 있고,
    - Sometimes just names of programs
      - 때로는 단순히 프로그램 이름일 뿐입니다
      - Adding new features doesn’t require shell modification
        - 새로운 기능을 추가해도 쉘을 수정할 필요가 없습니다

## System Calls

- The only way that a process communicates with the OS
- It provides an interface to the services made available by an OS

### System Calls

- **Programming interface to the services provided by the OS**
- Typically written in a high-level language (C or C++)
  - Sometimes written using assembly-language instructions.
- Mostly accessed by programs via a high-level Application Program Interface (API) rather than direct system call use
  - 대부분의 프로그램은 직접 시스템 호출을 사용하는 것보다 고급 응용 프로그램 인터페이스(API)를 통해 접근합니다.
  - Each API consists of one or more system calls.
    - 각 API는 하나 이상의 시스템 호출로 구성됩니다.
  - APIs are OS specific.
- **Three most common APIs:**
  - Win32 API, Win64 API for Windows
  - POSIX API for POSIX-based systems (including UNIX, Linux, Mac OS X)
  - Java API for the Java virtual machine (JVM)
- **Why use APIs rather than system calls?**
  - To provide a simplified method of the use of system calls and hide the implementation details.
    - 시스템 호출의 사용을 단순화하고 구현 세부 사항을 숨기기 위해서입니다.

![Screenshot 2024-10-12 at 21.07.04.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/55647248-39a1-4358-8284-1acde300ff9e/Screenshot_2024-10-12_at_21.07.04.png)

![Screenshot 2024-10-12 at 21.07.23.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/91d9c052-3ec4-480c-b151-b78db74f1cdb/Screenshot_2024-10-12_at_21.07.23.png)

## System Call Implementation

### 시스템 호출 구현

- **Typically, a number is associated with each system call**
  - 일반적으로 각 시스템 호출에는 번호가 할당됩니다.
  - System-call Interface maintains a table indexed according to these numbers
    - 시스템 호출 인터페이스는 이러한 번호에 따라 인덱싱된 테이블을 유지합니다.
  - The system call interface invokes the intended system call in the OS kernel and returns the status of the system call and any return values
    - 시스템 호출 인터페이스는 OS 커널에서 의도한 시스템 호출을 호출하고 시스템 호출의 상태 및 반환 값을 반환합니다.

- **The caller needs to know nothing about how the system call is implemented**
  - 호출자는 시스템 호출이 어떻게 구현되는지 알 필요가 없습니다.
  - Just needs to obey the API and understand what the OS will do as a result of the call
    - 단지 API를 준수하고 호출의 결과로 OS가 무엇을 할지 이해하면 됩니다.
  - Most details of the OS interface are hidden from programmers by the API
    - OS 인터페이스의 대부분의 세부 사항은 API를 통해 프로그래머에게 숨겨져 있습니다.

![Screenshot 2024-10-12 at 21.11.07.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/822f11b9-a3e9-4812-9e69-72668548c8f3/Screenshot_2024-10-12_at_21.11.07.png)

![Screenshot 2024-10-12 at 21.11.23.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/f7753073-63de-4bb0-bc3a-e05494ddc9b9/Screenshot_2024-10-12_at_21.11.23.png)

![Screenshot 2024-10-12 at 21.11.34.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/8cf35c92-42d8-42de-8772-c6092647da3f/Screenshot_2024-10-12_at_21.11.34.png)

## System Call Parameter Passing

### 시스템 호출 매개변수 전달

- **Often, more information is required than simple identity of desired system call**
  - 종종 원하는 시스템 호출의 단순한 식별 정보 이상의 정보가 필요합니다.
  - Exact type and amount of information vary according to OS and system call
    - 정확한 유형과 정보의 양은 운영 체제와 시스템 호출에 따라 다릅니다.

- **Three general methods used to pass parameters to the OS**
  - 운영 체제로 매개변수를 전달하는 데 사용되는 세 가지 일반적인 방법
  - **Simplest:** Pass the parameters in registers
    - 가장 간단한 방법: 매개변수를 레지스터에 전달
    - In some cases, may be more parameters than registers
      - 경우에 따라 레지스터보다 더 많은 매개변수가 있을 수 있습니다.
  - **Parameters stored in a block, or table, in memory, and address of block passed as a parameter in a register**
    - 매개변수를 메모리의 블록 또는 테이블에 저장하고, 블록의 주소를 레지스터에 매개변수로 전달
    - This approach is taken by Linux and Solaris
      - 이 방법은 Linux와 Solaris에서 사용됩니다.
  - **Parameters placed, or pushed, onto the stack by the program and popped off the stack by the operating system**
    - 프로그램이 매개변수를 스택에 넣거나 푸시하고, 운영 체제가 스택에서 팝하여 가져옴
  - **Block and stack methods do not limit the number or length of parameters being passed**
    - 블록 및 스택 방법은 전달되는 매개변수의 수나 길이에 제한을 두지 않습니다.

![Screenshot 2024-10-12 at 21.17.05.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/ca6e4e78-08c9-4d24-b411-a8d8be14bbda/Screenshot_2024-10-12_at_21.17.05.png)

## Types of System Calls

- **Five types of system calls**
  - Process control
  - File management
  - Device management
  - Information maintenance
  - Communications

### Process Control

- **프로세스 제어**
  - end, abort
    - 종료, 중단
  - load, execute
  - create process, terminate process
  - get process attributes, set process attributes
    - 프로세스 속성 가져오기, 프로세스 속성 설정
  - wait for time
  - wait for event, signal event
  - allocate and free memory

### Device Management

- **Device management**
  - request device, release device
  - read, write, reposition
  - get device attributes, set device attributes
  - logically attach or detach devices

### Information Maintenance

- **Information maintenance**
  - get time or date, set time or date
  - get system data, set system data
  - get process, file, or device attributes
  - set process, file, or device attributes

### Communications

- **Communications**
  - Create, delete communication connection
  - send, receive messages
  - transfer status information
  - attach or detach remote devices

## System Programs

- **System programs provide a convenient environment for program development and execution.**
  - 시스템 프로그램은 프로그램 개발 및 실행을 위한 편리한 환경을 제공합니다.
- Some of them are simply user interfaces to system calls; others are considerably more complex
  - 그 중 일부는 단순히 시스템 호출에 대한 사용자 인터페이스일 뿐이며, 다른 일부는 훨씬 더 복잡합니다.
- **They can be divided into:**
  - File manipulation
  - Status information
  - File modification
  - Programming language support
  - Programming loading and execution
  - Communications
    - 통신
- **Most users’ view of the operating system is defined by system programs, not the actual system calls.**
  - 대부분의 사용자가 보는 운영체제는 실제 시스템 호출이 아니라 시스템 프로그램에 의해 정의됩니다.

### File Management

- create, delete, copy, rename, print, dump, list, and generally manipulate files and directories

### Status Information

- **Some programs ask the system for info.**
  - date, time, amount of available memory, disk space, number of users.
  - detailed performance, logging, and debugging information.
- **Typically, these programs format and print the output to the terminal, other output devices, or files**
- **Some systems implement a registry** - used to store and retrieve configuration information.

### File Modification

- **Text editors to create and modify files**
- **Special commands to search contents of files or perform transformations of the text**

### Programming-language Support

- **Compilers, assemblers, debuggers, and interpreters sometimes provided**

### Program Loading and Execution

- **Once a program is assembled or compiled, it must be loaded into memory to be executed.**
- **Absolute loaders, re-locatable loaders, linkage editors, and overlay-loaders, debugging systems for higher-level and machine languages**

### Communications

- **Provide the mechanism for creating virtual connections among processes, users, and computer systems**
- **Allow users to send messages to another’s screens, browse web pages, send electronic-mail messages, log in remotely, transfer files from one machine to another.**

## OS Design and Implementation

### Operating System Design and Implementation

- **Design and Implementation of OS is not “solvable”**
  - but some approaches have proven successful
- **Internal structure of different OS can vary widely**

- **Defining goals and specifications**
  - Affected by choice of hardware, type of system
    - batch, multiprogramming, multitasking
    - single user, multi-user
    - distributed, real-time, general purpose.

### User Goals and System Goals

- **User goals**
  - Operating system should be convenient to use, easy to learn, reliable, safe, and fast
    - 운영체제는 사용하기 편리하고, 배우기 쉬우며, 안전하며, 빠르게 동작해야 합니다.
- **System goals**
  - Operating system should be easy to design, implement, and maintain, as well as flexible, reliable, error-free, and efficient
    - 운영체제는 설계, 구현, 유지 관리가 쉽고, 유연하며, 신뢰할 수 있고, 오류가 없으며, 효율적이어야 합니다.

### Important Principle to Separate

- **정책 (Policy):** What will be done?
  - 정책 : 무엇을 할 것인가?
- **메커니즘 (Mechanism):** How to do it?
  - 메커니즘 : 어떻게 할 것인가?

- **Mechanisms determine how to do something.**
- **Policies decide what will be done.**
  - The separation of policy from mechanism is a very important principle
    - 정책과 메커니즘의 분리는 매우 중요한 원칙입니다.
  - It allows maximum flexibility if policy decisions are to be changed later
    - 정책 결정이 나중에 변경될 경우 최대의 유연성을 제공합니다.
- **Once an operating system is designed, it must be implemented**
  - Traditionally, written in assembly language.
  - Now, written in high-level languages (C: Linux and Windows)

## Operating System Structure

1. Simple Structure
2. Layered Structure
3. Microkernel System Structure
4. Modular Kernel Structure - Modern OS

### 1. Simple Structure

- **MS-DOS**
  - **Policy**
    - To provide the must functionality in the least space
  - Not divided into modules
  - Although MS-DOS has some structure, its interfaces and levels of functionality are not well separated

![Screenshot 2024-10-12 at 21.40.23.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/f76a7147-1b3d-44df-9f13-36af4823f32b/Screenshot_2024-10-12_at_21.40.23.png)

### 2. Layered Approach

- **The operating system is divided into a number of layers (levels), each built on top of lower layers.**
  - The bottom layer (layer 0) is the hardware
  - The highest layer (layer N) is the user interface

- **With modularity, layers are selected such that each uses functions (operations) and services of only lower-level layers**
  - 모듈화에서는 각 계층이 하위 계층의 기능(작업)과 서비스만을 사용하도록 계층을 선택합니다.
  - A typical OS layer (layer M) consists of data structure and a set of routines that can be invoked by higher-level layers.
    - 일반적인 OS 계층(계층 M)은 데이터 구조와 상위 계층에서 호출할 수 있는 일련의 루틴으로 구성됩니다.
  - Layer M, in turn, can invoke operations on lower-level layers.
    - 계층 M은 차례로 하위 계층의 작업을 호출할 수 있습니다.

![Screenshot 2024-10-12 at 21.43.27.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/73725f11-dd72-4a2c-a93a-6dc2af7b4a18/Screenshot_2024-10-12_at_21.43.27.png)

### Layered Approach
**계층화된 접근**

- **Advantage**
  - Simplicity of construction and debugging
    - 구성 및 디버깅의 단순성
  - The design and implementation is simplified.
    - 설계 및 구현이 단순화됩니다.
  - Each layer is implemented with only those operations provided by lower-level layers.
    - 각 계층은 하위 계층에서 제공하는 작업만을 사용하여 구현됩니다.
  - A layer does not need to know how these operations are implemented.
    - 한 계층은 이러한 작업이 어떻게 구현되는지 알 필요가 없습니다.

- **Disadvantage**
  - Difficulty in appropriately defining the various layers
    - 다양한 계층을 적절하게 정의하는 데 어려움이 있음
  - Because a layer can use only lower-level layers, careful planning is necessary.
    - 계층이 하위 계층만을 사용할 수 있기 때문에 신중한 계획이 필요합니다.

### UNIX

- **The UNIX OS consists of two separable parts**
  - System programs
  - The kernel
    - Consists of everything below the system-call interface and above the physical hardware
    - Provides the file system, CPU scheduling, memory management, and other operating-system functions; a large number of functions for one level
- As UNIX expanded, the kernel became large.

![Screenshot 2024-10-12 at 21.47.49.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/358525be-704a-478b-8944-1bea177821ac/Screenshot_2024-10-12_at_21.47.49.png)

## 3. Microkernel System Structure

- **Make the kernel as light as possible.**
  - Moves as much from the kernel into “user” space
  - Communication takes place between user modules using message passing
    - 사용자 모듈 간의 통신은 메시지 전달을 사용하여 이루어집니다.
  - Mach OS from Carnegie Mellon Univ.

- **Advantage**
  - Easier to extend a microkernel
    - 마이크로커널을 확장하기 더 쉽습니다.
  - Easier to port the operating system to new architectures
    - 운영체제를 새로운 아키텍처로 포팅하기가 더 쉽습니다.
  - More reliable (less code is running in kernel mode) and secure
    - 더 신뢰할 수 있고 (커널 모드에서 실행되는 코드가 적음) 보안성이 높습니다.

- **Disadvantage**
  - Performance overhead of user space to kernel space communication
    - 사용자 공간과 커널 공간 간의 통신에 대한 성능 오버헤드

## 4. Modular Kernel Structure

- **Most modern operating systems implement kernel modules**
  - 대부분의 현대 운영 체제는 커널 모듈을 구현합니다.
  - The kernel has a set of core components and dynamically links to additional services either during boot time or during run time.
    - 커널은 핵심 구성 요소 세트를 가지고 있으며, 추가적인 서비스를 부팅 시 또는 실행 중에 동적으로 연결합니다.
  - Uses object-oriented approach
    - 객체 지향적 접근 방식을 사용합니다.
  - Each core component is separated
    - 각 핵심 구성 요소는 분리되어 있습니다.
  - Each talks to the others over known interfaces
    - 각 구성 요소는 알려진 인터페이스를 통해 서로 통신합니다.
  - Each is loadable as needed within the kernel
    - 각 구성 요소는 필요에 따라 커널 내에서 로드할 수 있습니다.
- **Overall, similar to layers but more flexible**
  - 전반적으로 계층 구조와 유사하지만 더 유연합니다.

![Screenshot 2024-10-12 at 21.54.54.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/4f0f9b70-659b-4e44-92cb-30201aecfed6/Screenshot_2024-10-12_at_21.54.54.png)

### Modular Kernel Structure

- **The Modular kernel approach is similar to the Layered approach**
  - 모듈형 커널 접근 방식은 계층형 접근 방식과 유사합니다.
  - The modular kernel approach requires subsystems to interact with each other through carefully constructed interfaces
    - 모듈형 커널 접근 방식은 서브시스템이 서로 상호작용할 때 신중하게 설계된 인터페이스를 통해 상호작용하도록 요구합니다.

- **However, the Modular kernel approach differs from the Layered approach**
  - The layered kernel imposes a strict ordering of subsystems such that subsystems at the lower layers are not allowed to invoke operations corresponding to the upper-layer subsystems.
    - 계층형 커널은 엄격한 서브시스템 순서를 강제하여 하위 계층의 서브시스템이 상위 계층 서브시스템에 해당하는 작업을 호출할 수 없도록 제한합니다.
  - There are no such restrictions in the modular-kernel approach, where modules are free to invoke each other without any constraints.
    - 모듈형 커널 접근 방식에서는 이러한 제한이 없으며, 모듈들이 서로 자유롭게 호출할 수 있습니다.

## Virtual Machines

### Virtual Machines

- **A virtual machine (VM)**
  - Takes the layered approach to its logical conclusion.
    - 계층적 접근 방식을 논리적 결론까지 발전시킨 개념입니다.
  - Treats hardware and the operating system kernel as though they were all hardware
    - 하드웨어와 운영체제 커널을 모두 하드웨어처럼 취급합니다.
  - Provides an interface identical to the underlying bare hardware
    - 기존 하드웨어와 동일한 인터페이스를 제공합니다.

- **A new guest OS is installed on a VM**
  - 새로운 게스트 OS가 가상 머신에 설치됩니다.

- **The guest OS creates the illusion of multiple processes**
  - 게스트 OS는 여러 프로세스의 환상을 만듭니다.
  - Each executing on its own processor with its own (virtual) memory
    - 각 프로세스는 자체 프로세서와 자체 (가상) 메모리에서 실행되는 것처럼 보입니다.

- **The resources of the physical computer are shared among the virtual machines**
  - 물리적 컴퓨터의 자원은 가상 머신들 간에 공유됩니다.

![Screenshot 2024-10-12 at 22.01.06.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/f7ed5546-7af3-45e7-8582-7f3f2782056e/Screenshot_2024-10-12_at_22.01.06.png)

### Virtual Machines

- **The virtual-machine concept provides complete protection of system resources**
  - 가상 머신 개념은 시스템 자원의 완벽한 보호를 제공합니다.
  - Since each virtual machine is isolated from all other virtual machines.
    - 각 가상 머신은 다른 가상 머신과 완전히 격리되어 있기 때문입니다.
  - This isolation, however, permits no direct sharing of resources.
    - 그러나 이 격리는 자원의 직접적인 공유를 허용하지 않습니다.

- **A virtual-machine system is a perfect vehicle for operating-systems research and development.**
  - 가상 머신 시스템은 운영체제 연구 및 개발에 완벽한 도구입니다.
  - System development is done on the virtual machine, instead of on a physical machine
    - 시스템 개발은 물리적 머신이 아닌 가상 머신에서 이루어지며,
  - So does not disrupt normal system operation.
    - 따라서 정상적인 시스템 운영을 방해하지 않습니다.

- **The virtual machine concept is difficult to implement**
  - 가상 머신 개념은 구현하기 어렵습니다.
  - Due to the effort required to provide an exact duplicate to the underlying machine
    - 이는 기본 머신과 동일한 복제본을 제공해야 하는 노력이 필요하기 때문입니다.

![Screenshot 2024-10-12 at 22.05.40.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/8872c6aa-26bc-42dc-bdb2-6c188ae372f9/Screenshot_2024-10-12_at_22.05.40.png)

![Screenshot 2024-10-12 at 22.05.51.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/264e00c3-1b5b-41c0-9e94-5b2c4e221332/182e6f6b-8c3b-4fd0-80ca-a96873ccce1f/Screenshot_2024-10-12_at_22.05.51.png)

## Summary

- **OS provides a number of services**
  - **Functions that are helpful to the user**
    - user interface, program execution, I/O operation
    - file system manipulation, communications, error detection
  - **Functions that ensure the efficient operation of the system**
    - resource allocation, accounting, protection and security

- **Three types of user interface from OS**
  - CLI, GUI, Batch Interface

- **System Calls allow a process to make requests to the OS.**
  - To send a request, programs use system APIs or standard library functions which are translated into a sequence of system calls.
    - 요청을 보내기 위해 프로그램은 시스템 API나 표준 라이브러리 함수를 사용하고, 이는 일련의 시스템 호출로 변환됩니다.

- **Three methods of parameter passing in system call**
  - Register, Block, Stack

- **The separation of policy from mechanism is a very important principle in the design of OS**

- **Four types of OS structures**
  - Simple, Layered, Microkernel, Modular

- **Virtual machine is an illusion of a computer system with its own CPU, memory, and I/O, which is created on top of the host OS.**

## Chapter 2 | 첫 번째 O/X 퀴즈

```
1.	운영 체제는 사용자 인터페이스, 프로그램 실행, I/O 작업 등을 포함한 여러 서비스를 제공합니다. O
2.	시스템 호출은 프로세스가 운영 체제에 요청을 할 수 있는 유일한 방법입니다. O
3.	모든 운영 체제는 그래픽 사용자 인터페이스(GUI)를 제공합니다. X
4.	시스템 프로그램은 시스템 호출에 대한 단순한 사용자 인터페이스만 제공합니다. O
5.	마이크로커널 구조는 커널을 가능한 한 가볍게 유지합니다. O
6.	모듈형 커널 구조에서는 각 모듈이 서로 자유롭게 호출할 수 있습니다. O
7.	가상 머신은 물리적 컴퓨터의 자원을 직접 공유할 수 있습니다. O
8.	정책과 메커니즘의 분리는 운영 체제 설계에서 중요하지 않습니다. X
9.	레지스터, 블록, 스택은 시스템 호출에서 매개변수를 전달하는 세 가지 방법입니다. O
10.	운영 체제의 계층화된 구조는 설계와 구현을 단순화시킵니다. O
11.	모든 시스템 호출은 번호와 연관되어 있습니다. O
12.	시스템 프로그램은 프로그램 개발 및 실행을 위한 편리한 환경을 제공합니다. O
13.	클라이언트는 시스템 호출이 어떻게 구현되는지 알아야 합니다. X
14.	UNIX 커널은 시스템 호출 인터페이스 아래와 물리적 하드웨어 위의 모든 것을 포함합니다. O
15.	마이크로커널 구조는 사용자 공간과 커널 공간 간의 통신 오버헤드가 적습니다. O
16.	모듈형 커널 구조는 계층형 구조보다 덜 유연합니다. X
17.	가상 머신은 운영 체제 연구 및 개발에 적합하지 않습니다. X
18.	운영 체제의 사용자 목표에는 사용하기 편리하고 배우기 쉬운 것이 포함됩니다. O
19.	시스템 호출은 주로 고급 응용 프로그램 인터페이스(API)를 통해 접근됩니다. O
20.	CLI는 그래픽 사용자 인터페이스의 한 종류입니다. X
21.	운영 체제의 시스템 목표에는 오류가 없고 효율적인 것이 포함됩니다. O
22.	시스템 호출 매개변수를 전달할 때 스택 방법은 매개변수의 수에 제한을 둡니다. O
23.	시스템 호출 인터페이스는 시스템 호출의 상태와 반환 값을 반환합니다. O
24.	운영 체제는 자원 할당, 회계, 보호 및 보안을 담당합니다. O
25.	모든 운영 체제는 모듈형 커널 구조를 채택하고 있습니다. X
26.	가상 머신은 실제 하드웨어와 동일한 인터페이스를 제공합니다. O
27.	배치 인터페이스는 사용자 인터페이스의 한 종류입니다. O
28.	시스템 프로그램 중 일부는 파일 조작을 담당합니다. O
29.	시스템 호출 매개변수 전달에서 레지스터 방법은 가장 복잡합니다. X
30.	정책과 메커니즘의 분리는 운영 체제의 유연성을 감소시킵니다. X
31.	CLI는 명령을 실행하기 위해 쉘을 사용합니다. O
32.	운영 체제의 구조는 하드웨어 선택에 영향을 받지 않습니다. X
33.	시스템 호출은 어셈블리어로만 작성됩니다. X
34.	마이크로커널 구조는 시스템의 보안을 향상시킵니다. O
35.	모듈형 커널 구조는 계층형 구조와 동일한 제한을 가집니다. O
36.	가상 머신은 하나의 프로세서와 메모리만을 가집니다. X
37.	시스템 호출의 블록 방법은 Linux와 Solaris에서 사용됩니다. O
38.	GUI는 사용자에게 명령을 직접 입력하도록 허용합니다. X
39.	시스템 호출 인터페이스는 시스템 호출 번호를 기반으로 테이블을 유지합니다. O
40.	운영 체제는 프로그램을 메모리에 로드하고 실행할 수 있어야 합니다. O
41.	운영 체제의 보호 기능은 시스템 자원에 대한 모든 접근을 통제하는 것을 포함합니다. O
42.	시스템 프로그램은 항상 복잡한 기능만을 제공합니다. X
43.	시스템 호출은 직접적으로 사용자 프로그램에 의해 호출됩니다. X
44.	계층형 커널 구조는 서브시스템 간의 자유로운 호출을 허용합니다. O
45.	가상 머신은 운영 체제의 성능을 향상시킵니다. X
46.	시스템 프로그램은 대부분의 사용자들이 실제 시스템 호출을 보지 못하게 합니다. O
47.	운영 체제의 설계 목표에는 시스템의 유연성이 포함되지 않습니다. X
48.	시스템 호출 매개변수 전달에서 레지스터 방법은 가장 단순합니다. O
49.	시스템 호출은 사용자와 운영 체제 간의 인터페이스를 제공합니다. O
50.	모듈형 커널 구조는 각 핵심 구성 요소가 서로를 알 필요가 없도록 합니다. O
```

## Chapter 2 | 첫 번째 O/X 퀴즈 정답 및 해설

1.	**O** - 맞았습니다.

운영 체제는 사용자 인터페이스, 프로그램 실행, I/O 작업 등을 포함한 여러 서비스를 제공합니다.

2.	**O** - 맞았습니다.

시스템 호출은 프로세스가 운영 체제에 요청을 할 수 있는 유일한 방법입니다.

3.	**X** - 맞았습니다.

모든 운영 체제가 GUI를 제공하는 것은 아닙니다. 일부는 CLI만을 제공합니다.

4.	**O** - **틀렸습니다.**

**해설:** 시스템 프로그램은 단순한 사용자 인터페이스뿐만 아니라 파일 조작, 프로그래밍 언어 지원 등 다양한 기능을 제공합니다. 따라서 "시스템 프로그램은 시스템 호출에 대한 단순한 사용자 인터페이스만 제공합니다."라는 진술은 **거짓**입니다.

5.	**O** - 맞았습니다.

마이크로커널 구조는 커널을 가능한 한 가볍게 유지합니다.

6.	**O** - 맞았습니다.

모듈형 커널 구조에서는 각 모듈이 서로 자유롭게 호출할 수 있습니다.

7.	**O** - **틀렸습니다.**

**해설:** 가상 머신은 물리적 컴퓨터의 자원을 직접 공유하지 않고, 물리적 자원을 가상 머신들 간에 간접적으로 공유합니다. 따라서 "가상 머신은 물리적 컴퓨터의 자원을 직접 공유할 수 있습니다."라는 진술은 **거짓**입니다.

8.	**X** - 맞았습니다.

정책과 메커니즘의 분리는 운영 체제 설계에서 중요하지 않습니다.

9.	**O** - 맞았습니다.

레지스터, 블록, 스택은 시스템 호출에서 매개변수를 전달하는 세 가지 방법입니다.

10.	**O** - 맞았습니다.

운영 체제의 계층화된 구조는 설계와 구현을 단순화시킵니다.

11.	**O** - 맞았습니다.

모든 시스템 호출은 번호와 연관되어 있습니다.

12.	**O** - 맞았습니다.

시스템 프로그램은 프로그램 개발 및 실행을 위한 편리한 환경을 제공합니다.

13.	**X** - 맞았습니다.

클라이언트는 시스템 호출이 어떻게 구현되는지 알아야 합니다.

14.	**O** - 맞았습니다.

UNIX 커널은 시스템 호출 인터페이스 아래와 물리적 하드웨어 위의 모든 것을 포함합니다.

15.	**O** - **틀렸습니다.**

**해설:** 마이크로커널 구조는 사용자 공간과 커널 공간 간의 통신 오버헤드가 큽니다. "마이크로커널 구조는 사용자 공간과 커널 공간 간의 통신 오버헤드가 적습니다."라는 진술은 **거짓**입니다.

16.	**X** - 맞았습니다.

모듈형 커널 구조는 계층형 구조보다 덜 유연합니다.

17.	**X** - 맞았습니다.

가상 머신은 운영 체제 연구 및 개발에 적합하지 않습니다.

18.	**O** - 맞았습니다.

운영 체제의 사용자 목표에는 사용하기 편리하고 배우기 쉬운 것이 포함됩니다.

19.	**O** - 맞았습니다.

시스템 호출은 주로 고급 응용 프로그램 인터페이스(API)를 통해 접근됩니다.

20.	**X** - 맞았습니다.

CLI는 그래픽 사용자 인터페이스의 한 종류입니다.

21.	**O** - 맞았습니다.

운영 체제의 시스템 목표에는 오류가 없고 효율적인 것이 포함됩니다.

22.	**O** - **틀렸습니다.**

**해설:** 시스템 호출 매개변수를 전달할 때 스택 방법은 매개변수의 수에 제한을 두지 않습니다. "시스템 호출 매개변수를 전달할 때 스택 방법은 매개변수의 수에 제한을 둡니다."라는 진술은 **거짓**입니다.

23.	**O** - 맞았습니다.

시스템 호출 인터페이스는 시스템 호출의 상태와 반환 값을 반환합니다.

24.	**O** - 맞았습니다.

운영 체제는 자원 할당, 회계, 보호 및 보안을 담당합니다.

25.	**X** - 맞았습니다.

모든 운영 체제가 모듈형 커널 구조를 채택하고 있지 않습니다. 일부는 다른 구조를 사용합니다.

26.	**O** - 맞았습니다.

가상 머신은 실제 하드웨어와 동일한 인터페이스를 제공합니다.

27.	**O** - 맞았습니다.

배치 인터페이스는 사용자 인터페이스의 한 종류입니다.

28.	**O** - 맞았습니다.

시스템 프로그램 중 일부는 파일 조작을 담당합니다.

29.	**X** - 맞았습니다.

시스템 호출 매개변수 전달에서 레지스터 방법은 가장 복잡합니다.

30.	**X** - 맞았습니다.

정책과 메커니즘의 분리는 운영 체제의 유연성을 감소시킵니다.

31.	**O** - 맞았습니다.

CLI는 명령을 실행하기 위해 쉘을 사용합니다.

32.	**X** - 맞았습니다.

운영 체제의 구조는 하드웨어 선택에 영향을 받지 않습니다.

33.	**X** - 맞았습니다.

시스템 호출은 어셈블리어로만 작성됩니다.

34.	**O** - 맞았습니다.

마이크로커널 구조는 시스템의 보안을 향상시킵니다.

35.	**O** - **틀렸습니다.**

**해설:** 모듈형 커널 구조는 계층형 구조와 동일한 제한을 가지지 않습니다. "모듈형 커널 구조는 계층형 구조와 동일한 제한을 가집니다."라는 진술은 **거짓**입니다.

36.	**X** - 맞았습니다.

가상 머신은 하나의 프로세서와 메모리만을 가집니다.

37.	**O** - 맞았습니다.

시스템 호출의 블록 방법은 Linux와 Solaris에서 사용됩니다.

38.	**X** - 맞았습니다.

GUI는 사용자에게 명령을 직접 입력하도록 허용합니다.

39.	**O** - 맞았습니다.

시스템 호출 인터페이스는 시스템 호출 번호를 기반으로 테이블을 유지합니다.

40.	**O** - 맞았습니다.

운영 체제는 프로그램을 메모리에 로드하고 실행할 수 있어야 합니다.

41.	**O** - 맞았습니다.

운영 체제의 보호 기능은 시스템 자원에 대한 모든 접근을 통제하는 것을 포함합니다.

42.	**X** - 맞았습니다.

시스템 프로그램은 항상 복잡한 기능만을 제공합니다.

43.	**X** - 맞았습니다.

시스템 호출은 직접적으로 사용자 프로그램에 의해 호출됩니다.

44.	**O** - **틀렸습니다.**

**해설:** 계층형 커널 구조는 서브시스템 간의 자유로운 호출을 허용하지 않습니다. "계층형 커널 구조는 서브시스템 간의 자유로운 호출을 허용합니다."라는 진술은 **거짓**입니다.

45.	**X** - 맞았습니다.

가상 머신은 운영 체제의 성능을 향상시킵니다.

46.	**O** - 맞았습니다.

시스템 프로그램은 대부분의 사용자들이 실제 시스템 호출을 보지 못하게 합니다.

47.	**X** - 맞았습니다.

운영 체제의 설계 목표에는 시스템의 유연성이 포함되지 않습니다.

48.	**O** - 맞았습니다.

시스템 호출 매개변수 전달에서 레지스터 방법은 가장 단순합니다.

49.	**O** - 맞았습니다.

시스템 호출은 사용자와 운영 체제 간의 인터페이스를 제공합니다.

50.	**O** - **틀렸습니다.**

**해설:** 모듈형 커널 구조는 각 핵심 구성 요소가 서로를 알 필요가 없도록 합니다. 그러나 사용자의 답변에서는 “모듈형 커널 구조는 각 핵심 구성 요소가 서로를 알 필요가 없도록 합니다.“라고 했지만, 이는 사실과 반대입니다. 실제로 모듈형 커널 구조는 각 모듈이 알려진 인터페이스를 통해 서로를 호출할 수 있도록 설계되어 있으므로, “각 핵심 구성 요소가 서로를 알 필요가 없도록 한다”는 진술은 **거짓**입니다.

---

## 총 틀린 개수: 7개

**틀린 문제 번호 및 해설:**

- **4번:** 시스템 프로그램은 단순한 사용자 인터페이스뿐만 아니라 다양한 기능을 제공합니다.
- **7번:** 가상 머신은 물리적 자원을 직접 공유하지 않습니다.
- **15번:** 마이크로커널 구조는 사용자 공간과 커널 공간 간의 통신 오버헤드가 큽니다.
- **22번:** 시스템 호출 매개변수를 전달할 때 스택 방법은 매개변수의 수에 제한을 두지 않습니다.
- **35번:** 모듈형 커널 구조는 계층형 구조와 동일한 제한을 가지지 않습니다.
- **44번:** 계층형 커널 구조는 서브시스템 간의 자유로운 호출을 허용하지 않습니다.
- **50번:** 모듈형 커널 구조는 각 핵심 구성 요소가 서로를 알 필요가 없도록 설계되지 않았습니다.

틀린 답안들을 다시 복습하시고, 관련 개념을 재확인해 보시기 바랍니다.