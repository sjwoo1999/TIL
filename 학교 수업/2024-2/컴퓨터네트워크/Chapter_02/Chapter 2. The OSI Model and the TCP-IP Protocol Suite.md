<h1>Chapter 2</h1>
<h2>The OSI Model and the TCP/IP Protocl Suite</h2>

<h3>2.1 Protocol Layers</h3>

<h3>Components</h3>

<h3>Example 2.1</h3>

<h3>Example 2.2</h3>

- Logical
    - Maria와 Ann이 대화
    - 중간 부분을 코드화 ..
    - 통신할 때 나눠서 처리한다 .. Layering ..

![alt text](image.png)

<h3>2.2 The OSI Model</h3>

- Layer 7 : Application
- Layer 6 : Presentation
- Layer 5 : Session
- Layer 4 : Transport
- Layer 3 : Network
- Layer 2 : Data link
- Layer 1 : Physical

<h3>Figure 2.4 OSI layers</h3>

![alt text](image-2.png)

- 우체국 아저씨 : 스페인어랑 영어를 할 수 있다고 하더라도 편지를 열어보진 않기 때문에 다른 레이어 관련된 무언가가 필요하지 않다.

<h3>Figure 2.5 An exchange using the OSI model</h3>

![alt text](image-3.png)

- 실제 데이터가 D7이라고 했을 때, 각 Layer에서 할 수 있는 일들을 Header에 담아서 전달한다.
- 해당 레이어에서의 데이터와 Header까지를 묶어서 다음 Layer의 데이터로 전달한다.
- 헤더의 경우 다른 Layer의 헤더에는 관심을 갖지 않는다.
- D2의 경우에는 Tail도 붙이긴 하는데 이 부분에 대해서는 나중에 추가로 알아보도록 하자.
- 사실 D2를 보내는데 보낼 때는 엄청나게 많은 양을 보내게 된다. 효율적일까 비효율적일까? 당연히 매우 비효율적이다. 하지만 이러한 것은 Layering을 위해 필요한 작업이다. 다른 Layer에서 뭔가 문제가 발생할 경우에도 맨 위에서 실제로 전달되는 내용이 바뀌거나 그러지 않기 때문이다. (이 부분 다시 한번 체크해보면 좋을 듯?) 문제가 없긴 하지만, 주고받는 데이터의 양이 많아지긴 한다.

<h3>Layers in the OSI Model</h3>

- Physical Layer
    - 비트 전송에 관심이 있는 레이어
    - 비트의 형태로 전송을 한다.
    - Physical characteristics of interfaces and media
    - Representation of bits (encoding)
    - Data rate
        - 얼마나 빨리 전송하냐? 얼마나 느리게 전송하냐?
        - 순서대로 잘 받아야 한다.
        - 싱크가 맞지 않는다면 순서가 바뀌게 된다.
    - Synchronization of bits (clock synchronization)
    - Line configuration (point-to-point, multipoint configuration)
    <img src="Screenshot 2024-09-17 at 16.01.42.png" width="200" height="400" />
    - Physical topology (mesh, star, ring, and bus topologies)
        - 하나의 버스 .. 충돌이 발생하는 경우 .. 많은 방식이 있을 수 있으나..
        - 전달하고 있는지 아닌지 체크 후 전달
        - 비트 .. Physical Layer
    - Transmission mode (simple, half-duplex, and full-duplex modes)
        - half-duplex
            - 말하고 듣고 동시에 안 됨
            - 무전기
        - full-duplex
            - 말하고 듣고 가능, 채널 2개
            - 전화
- Data Link Layer
    - Framing (frame : data unit)
        - 001101101 : 하나의 덩어리로 만들기
        - 주소 : Physical 주소 : 물리 주소
    - Physical addressing
        - 선상도
        ![alt text](image-4.png)
        - Header
            - 어떤 녀석이야~~ 하는 정보를 제공
            - 잘 도착하면 에러 잇고 없고 체크 가능
            - 에러가 있다면 다시 보내줘
            ![alt text](<Screenshot 2024-09-17 at 16.15.06.png>)
    - Flow control (Hop-to-Hop control)
        - 잘못된 게 있다면 멈추고 다시 보내야 함 : 멈춘다 : flow control
    - Error control (using trailer)
    - Access control (determine which device has control over the link at any given time)
    - 기지국에 말해야 이야기가 전달된다고 해보자. 이런 경우 여럿이 동시에 말하는 경우 충돌이 발생하게 되고, 모두 이야기 할 수 없다. 충돌 발생 않고 잘 이야기 할 수 있도록 Data Link Layer에서 이러한 작업을 담당하고 있다.

    ![alt text](image-5.png)
    <br>
- Network Layer : 길
    - Logical addressing
    - Routing
    - IP(Internet protocol)
    - 한 학기 동안 자세하게 배울 것 ..
    - 컴퓨터 자체의 주소 : Physical Address : 물리 주소
    - 접속한 위치에 따른 주소 : Logical Address : IP
- Transport Layer
    - Service-port addressing (port address)
    - Segmentation and reassembly (include numbering)
        - 데이터 길 경우 쪼개야 한다.
        - 쪼갠 데이터를 다 받은 경우 순서대로 다시 연결해주어야 한다.
    - Connection control (connectionless(UDP) and connection-oriented(TCP, SCTP))
        - connectionless
            - 한 번 데이터 보내면 연결 끊기는 것
        - connection-oriented(TCP, SCTP)
            - 한 번 데이터 보내게 되면 데이터 전송이 다 끝나기 전까지 계속 유지되는 것
            - 인터넷 .. 업로드 .. 다운로드 ..
            
            <t/>![alt text](image-6.png)

    - Flow control (for End-to-End control)
    - Error control (using retransmission generally, for End-to-End control)
        - Flow control과 Error control은 Data Link Layer에서도, 여기에서도
- Session Layer : 연결관계
        - Session 연결 ..
    - Dialog control (half-duplex or full-duplex mode)
    - Synchronization (using checkpoint)
        - Naver에서 로그인하고 이메일로 들어갔을 때 .. 세션 유지되어야 한다.
        - 세션을 적용시키지 않고 데이터를 주소에 담게 된다면 주소가 유출될 경우 다른 사람들이 내 메일을 볼 수 있다.
        - 하지만 세션을 적용시킨다면 주소를 복붙하더라도 세션에 대한 정보가 존재하지 않기 때문에 다른 사람들이 내 메일을 볼 수 없다.
- Presentation Layer
    - Translation (change the information to a common format)
    - Encryption (and Decryption) / Encoding (and Decoding)
    - Compression (reduces the number of bits)
- Application Layer
    - Network virtual terminal (allows a user to log on to a remote host)
    - FTAM : file transfer, access, and management (for remote control)
    - E-mail service (X.400) : 프로그램 설치하게 되면 거기에 해당하는 동작 개념이 있어야 한다.
    - Directory service (X.500)

<h3>2.3 TCP/IP Protocol Suite</h3>

- The TCP/IP protocol suite is made of five layers:
    - physical, data link, network, transport, and application

<h3>Figure 2.7 Layers in the TCP/IP Protocol Suite</h3>

![alt text](image-7.png)

<h3>Figure 2.8 TCP/IP and OSI model</h3>

![alt text](image-8.png)

![alt text](image-9.png)

- OSI Model
    - Physical Layer
        - 비트 표현 전송
    - Data Link Layer
        - Bit 모아서 Frame 생성
        - Flow Control
        - Error Control
        - Access Control
    - Network Layer
        - 길 찾기
        - 주소 갖고 다음 Hop으로 넘겨주기
    - Transport Layer
        - Data 쪼개서 보낼 수 있도록
        - 받은 데이터 합치기
        - Flow Control
        - Error Control
    - Session
        - Session 유지되도록
    - Presentation
        - Data 표현
    - Application
        - 프로그램 설치 등
    
<h3>Figure 2.9 A private internet</h3>

- 데이터 전송 과정
- Layer 무슨 일 어떻게 진행
- internet
    - Network와 Network의 연결
- We assume that we want to use the TCP/IP suite in a small, private internet.

<h3>Figure 2.10 Communication at the physical layer</h3>

![alt text](image-10.png)

- Link
    - A와 R1이 Data 전송할 수 있는 통로
- 경로(과정)는 정해져있다고 가정하자. 길 찾는 건 뒤에서.
- The unit of communication at the physical layer is a "bit".

<h3>Figure 2.11 Communication at the data link layer</h3>

![alt text](image-11.png)

- Data Link Layer
    - Header
        - 하는 일에 대한 정보
- The unit of communication at the data link layer is a "frame".

<h3>Figure 2.12 Communication at the network layer</h3>

![alt text](image-12.png)

- 어디로 전송하면 되는 거야 .. 확인할 수 있는 정보는 Network Layer
- Network Layer에 도착해야 주소를 확인할 수 있다
- 주소를 확인해야 다음 어디로 갈 수 있는지를 확인할 수 있다.
- The unit of communication at the network layer is a "datagram".

<h3>Figure 2.13 Communication at the transport layer</h3>

![alt text](image-13.png)

- A와 B 관점에서는 Transport가 연결된 것처럼 보인다.
- 나머지는 Trasnport가 없기 때문.
- A와 B의 Transport : 자기네들끼리 연결된 것처럼 느낄 수 있다. 실제로는 아니지만.
- The unit of communication at the transport layer is a "segment", user "datagram", or a "packet", depending on the specific protocol used in this layer.

<h3>Figure 2.14 Communication at the application layer</h3>

![alt text](image-14.png)

- Transport X / Application X
- The unit of communication at the application layer is a "message".

<h3>TCP/IP Protocol Suite and OSI Model</h3>

![alt text](image-15.png)

- Network
    - IP (Internet Protocol)
        - 잘 도착했는지? 잘 도착하지 않았는지?
    - IP가 못하는 것 ..
        - ICMP, IGMP, ARP가 도와줌
        - Network Layer 길 찾는 곳에 관심
- Presentation
    - FTP : 파일 다운
    - HTTP : 인터넷 주소 체계
    - DNS : 차후에 ..

<h3>TCP/IP Protocol Suite and OSI Model</h3>

- TCP/IP Protocol
    - Physical and Data Link Layer
        - It supports all of standard and proprietary protocols.
    - Network Layer
        - IP : a best-effort delivery service.
            - 가장 좋게 보낸다.
            - 통로 .. 주어진 환경에 따라 보낼 수 있는 양 달라짐.

                ![alt text](image-16.png)        
        - ARP and RARP
        - ICMP (Internet Control Message Protocol)
        - IGMP (Internet Group Message Protocol)
    - Transport Layer
        - UDP (User Datagram Protocol)
        - TCP (Transmission Control Protocol)
        - SCTP (Stream Control Transmission Protocol)
    - Application Layer
        - It is equivalent to combined session, presentation and application layers in the OSI model.

<h3>2.4 Addressing</h3>

- Four levels of addresses are used in an internet employing the TCP/IP protocols:
    - physical address
        - Data Link Layer
        - 어떻게 찾아갈 거냐?
    - logical address
        - IP
        - Network Layer
    - port address
        - Transport Layer
    - applicatoin-specific address
        - Application

<h3>Figure 2.15 Address in TCP/IP protocol suite</h3>

![alt text](image-17.png)

<h3>Figure 2.16 Example 2.3: physical addresses</h3>

![alt text](image-18.png)

- LAN
    - Local Area Network
- 내가 아니네? 데이터 무시 ...
- Physical Layer -> 확인불가
    - 왜? Bit가 전송되므로
- Data Link Layer -> 확인 가능
    - 왜? frame이라고 했으므로
    - frame 안에 Destination, Source 주소들이 존재
- 주소 확인은 Network Layer에서 한다고 했는데, 뭐가 이상하지 않나?
    - Data Link Layer
    - Source Address ..
    - 두 개 주소 다르다 ..
    - Data Link Layer에서 주소는 .. Physical Address (물리 주소) PC 고유번호..
    - 87이 Receiver의 Physical Address라는 걸 알게 됨
    - ARP 프로토콜 사용해서 .. 너의 Physical Address는 뭐니?
    - 이때 보내는 Physical Address 주소 알게 됨

<h3>Example 2.4</h3>

- Most local area networks use a 48-bit (6 bytes) physical address written as 12 hexadecimal digits; every byte (2 hexadecimal digits) is seperated by a clon, as shown below:

![alt text](image-19.png)

<h3>Figure 2.17 Example 2.5: logical addresses <- Network Layer</h3>

![alt text](image-20.png)

- 20 / 10 / A / P / Data

- frame / Datagram

- Logical Address / Physical Address

- Router
    - Physical 주소 2개
    - Logical 주소 2개
    - 다른 Network와도 연결된다면 더욱 증가할 것

- 95/66
    - 동네에서 누가 나에게 보냈는지
- A/P
    - 다른 동네 누가 나에게 보냈는지 ..

- Network는 하나의 방이라고 생각할 수 있다.
    - 나중에 IP 배울 때 더욱 자세히 ..

- Frame을 받아서 Physical Adderss를 붙여서 전달한다 .. 전달하려면 붙여야만 한다
    - 이건 다시 체크해봐야 할 듯?

- The physical addresses will change from hop to hop, but the logical addresses remain the same.
- 같은 동네에서 어떠한 녀석이 나에게 보냈는지에 관심이 있음
- Logical addresses
    - 누가 나에게 보냈냐
- Logical Address는 변화 X
- Physical Address는 다른 동네로 가면서 변화
    - 동네 : 다 들을 수 있는 .. 내 것인지 아닌지
- 다른 동네로 가면 Physical address 바뀐다
- Router
    - 양쪽 동네 다 들을 수 있음
    - 주소가 2개

<h3>Figure 2.18 Example 2.6: port numbers <- Transport Layer</h3>

- 프로그램 설치 -> 인식할 수 있는 port가 존재
- Physical Address/Logical Address => Destination Node => Port Address(내 컴퓨터 안에 있는 특정 Port의 Adddress)
- The physical addresses change from hop to hop, but the logical and port addresses usually remain the same.

<h3>Application-Specific Address</h3>

- Some applications have user-friendly addresses that are designed for that specific application.
- Examples of Application-Specific Address
    - E-mail
    - URL(Universal Resource Locator)
- These addresses get changed to the corresponding port and logical addresses by the sending computer.