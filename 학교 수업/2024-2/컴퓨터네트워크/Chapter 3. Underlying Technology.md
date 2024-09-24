<h1>Chapter 3</h1>
<h2>Underlying Technology</h2>

<h3>3.1 Local Area Networks</h3>

- **A Local Area Network (LAN):**
    - A computer network designed for a limited geographic area, such as a building or a campus.
    - Although a LAN can be used as an isolated network to connect computers in an organization for the sole purpose of sharing resources, most LANs today are also linked to a Wide Area Network (WAN) or the Internet.

<h3>Figure 3.1 IEEE Standard for LANs</h3>

<h3>Figure 3.2 Ethernet Frame</h3>

- **Frame Format:**
    - **Preamble:** 수신측에 프레임 도착 통지, 시스템 타이머 동기 맞춤
    - **Start Frame Delimiter (SFD):** 프레임 시작을 알림
    - **Destination Address:** 다음 국의 물리 주소
    - **Source Address:** 이전 국의 물리 주소
    - **Type:** 데이터 유형 지정
    - **Data:** 상위층으로부터 받은 데이터, 46 ~ 1,500바이트 사이
    - **Cyclic Redundancy Check (CRC):** 오류 검출

<h3>Figure 3.3 Maximum and Minimum Lengths</h3>

<h3>Figure 3.4 Ethernet Address in Hexadecimal Notation</h3>

<h3>Ethernet Evolution</h3>

- **Standard Ethernet**
- **Fast Ethernet:** 100 Mbps
- **Gigabit Ethernet:** 1 Gbps
- **Ten-Gigabit Ethernet:** 10 Gbps

<h3>Figure 3.6 Ethernet Evolution Through Four Generations</h3>

<h3>Figure 3.7 Space/Time Model of a Collision in CSMA</h3>

- **Standard Ethernet:**
    - **Data Rate:** 1 - 10 Mbps
    - **Access Method:** CSMA/CD (Carrier Sense Multiple Access with Collision Detection) – listen before talk

<h3>Figure 3.8 Collision of the First Bit in CSMA/CD</h3>

<h3>Minimum Frame Size</h3>

- For CSMA/CD to work, the frame size is restricted.
- Before sending the last bit of the frame, the sending station must detect a collision, if any, and abort the transmission.
- Therefore, the frame transmission time \( T_{fr} \) must be at least two times the maximum propagation time \( T_p \).

- **Minimum frame length/Transmission rate is proportional to Collision domain/Propagation speed**

<h3>Example 3.3</h3>

- **Problem:** In the standard Ethernet, if the maximum propagation time is 25.6 μs, what is the minimum size of the frame?
- **Solution:**
    - The frame transmission time is \( T_{fr} = 2 \times T_p = 51.2 \ \mu s \).
    - This means, in the worst case, a station needs to transmit for a period of 51.2 μs to detect the collision.
    - The minimum size of the frame is \( 10 \ Mbps \times 51.2 \ \mu s = 512 \ bits \) or 64 bytes.
    - This is actually the minimum size of the frame for Standard Ethernet.

---

<h3>3.2 Wireless LANs</h3>

- **Wireless Communication:**
    - One of the fastest-growing technologies.
    - The demand for connecting devices without the use of cables is increasing everywhere.
    - Wireless LANs can be found on college campuses, in office buildings, and in many public areas.

- **Technologies:**
    - **IEEE 802.11 Wireless LANs:** Sometimes called wireless Ethernet.
    - **Bluetooth:** A technology for small wireless LANs.

<h3>IEEE 802 Organization</h3>

<h3>Figure 3.13 Basic Service Sets (BSSs)</h3>

- **WLAN Architecture:**
    - **Basic Service Set (BSS):**
        - Building block of WLAN.
        - BSS without an Access Point (AP) is a stand-alone network and cannot send data to other BSSs: ad hoc network.

<h3>Figure 3.14 Extended Service Sets (ESSs)</h3>

- **Extended Service Set (ESS):**
    - Two or more BSSs.
    - Connected through a distribution system that connects the APs in the BSSs.

<h3>MAC Sublayer</h3>

- **Limitations of CSMA/CD in Wireless LANs:**
    - For collision detection, a station must be able to send data and receive collision signals at the same time, which can be costly and increase bandwidth requirements.
    - Collisions may not be detected due to hidden stations.
    - Signal strength decreases proportional to the square of the distance; signal fading could prevent a station at one end from hearing a collision at the other end.

<h3>Figure 3.16 CSMA/CA and NAV</h3>

- **CSMA/CA and NAV (Network Allocation Vector):**
    - The channel uses a 1-persistent strategy with back-off until the channel is idle.
    - After the station finds the channel to be idle, it waits for a DIFS, then sends an RTS.

<h3>MAC Sublayer Functions</h3>

- **Distributed Coordination Function (DCF):**
    - **NAV (Network Allocation Vector):**
        - When a station sends an RTS, it includes the duration of time it needs to occupy the channel.
        - Other stations set their NAV timer based on this duration.
    - **Collision During Handshaking:**
        - If the sender does not receive a CTS, it assumes a collision has occurred and employs a back-off strategy before retrying.

- **Point Coordination Function (PCF):**
    - Used for time-sensitive transmissions.
    - Employs a centralized, contention-free polling access method.
    - **To give priority to PCF over DCF, a new interval PIFS (PCF Inter-Frame Space) is defined.**
    - The repetition interval starts with a beacon frame; stations set their NAV timers during the contention-free period.

<h3>Inter-Frame Spaces and Priorities</h3>

- **SIFS (Short Inter-Frame Spacing):**
    - Highest priority; used for ACKs, CTS, and polling responses.
- **PIFS (PCF IFS):**
    - Medium priority; used for time-bounded services using PCF.
- **DIFS (DCF IFS):**
    - Lowest priority; used for asynchronous data services.

<h3>Figure 3.17 Frame Format</h3>

- **Frame Types:**
    - **Management Frames:** For initial communication between stations and APs.
    - **Control Frames:** For accessing the channel and acknowledging frames.
    - **Data Frames:** For carrying data and control information.

<h3>Hidden Station Problem</h3>

<h4>Figure 3.19 Hidden Station Problem</h4>

- **Explanation:**
    - Station B sends to A; Station C cannot detect A.
    - Station C wants to send to A; C senses the medium is free and transmits, leading to a collision at A.
    - B is "hidden" from C.

<h3>Figure 3.20 Use of Handshaking to Prevent Hidden Station Problem</h3>

- **Solution:**
    - Use RTS/CTS handshaking.
    - B sends an RTS to A; A responds with a CTS.
    - C, upon hearing the CTS, defers its transmission, preventing collision.

<h3>Exposed Station Problem</h3>

<h4>Figure 3.21 Exposed Station Problem</h4>

- **Explanation:**
    - A sends to B; C wants to send to D.
    - C senses the medium is busy due to A's transmission and refrains from sending, even though it could have transmitted without interference.
    - C is "exposed" to A's transmission unnecessarily.

<h3>Bluetooth Technology</h3>

- **Overview:**
    - Short-range wireless communication technology for creating Personal Area Networks (PANs).
    - Operates in the 2.4 GHz ISM band with a signal strength of 1 milliwatt.
    - Typical operating range of 10 meters (optional 100 meters mode).
    - Uses spread spectrum and frequency hopping to avoid interference.
    - Provides multiple levels of security.

<h3>Bluetooth Network Topology</h3>

- **Piconet:**
    - One master and up to seven active slaves.
    - Each piconet has a unique hopping pattern/ID.
- **Scatternet:**
    - Multiple piconets interconnected through shared devices.

<h3>Radio Layer and Frequency Hopping</h3>

- Operates in the 2.4 GHz ISM bands.
- Hop time: 625 μs (1/1600 seconds).
- **Frequency Hopping Principle:**

- Performs 1600 hops per second to minimize interference.

<h3>Physical Links</h3>

- **Synchronous Connection-Oriented (SCO) Link:**
    - Symmetrical, circuit-switched, point-to-point.
- **Asynchronous Connectionless Link (ACL):**
    - Packet-switched, point-to-multipoint; master polls slaves.

<h3>Frame Header Types</h3>

- **Parameters:**
    - **AM_ADDR:** Active member address.
    - **TYPE:** Payload type.
    - **FLOW:** Flow control.
    - **ARQN:** Acknowledgment (ACK/NAK).
    - **SEQN:** Sequence number for retransmission ordering.
    - **HEC:** Header error check.

---

<h3>3.3 Point-to-Point WANs</h3>

- **Introduction:**
    - Point-to-point WANs connect two remote devices using lines available from public networks like the telephone network.
    - Technologies include traditional modem technology, DSL lines, cable modems, T-lines, and SONET.

<h3>An Imaginary Part of the Internet</h3>

<h3>Figure 3.26 56K Modem</h3>

- **56K Modem:**
    - **Downloading:** No quantization noise; allows for higher speeds.
    - **Uploading:** Presence of quantization noise; speeds are lower compared to downloading.

<h3>DSL Technology</h3>

- **ADSL (Asymmetric Digital Subscriber Line):**
    - Utilizes existing local loops (telephone lines) that can handle bandwidths up to 1.1 MHz.
    - ADSL is an adaptive technology; data rates are based on the condition of the local loop line.
    - **Note:** ADSL is an asymmetric communication technology designed for residential users; it is not suitable for businesses due to its unequal bandwidth distribution.

<h3>Figure 3.27 Bandwidth Division</h3>

- **Bandwidth Allocation:**
    - **Voice:** 4 kHz channel.
    - **Upstream Data Band:**
        - Channels 6~30.
        - 25 channels (24 for data, 1 for control).
        - Standard data rate ranges from 64 Kbps to 1 Mbps.
    - **Downstream Data Band:**
        - Channels 31~255.
        - 225 channels (224 for data, 1 for control).
        - Standard data rate ranges from 500 Kbps to 8 Mbps.

<h3>Figure 3.28 ADSL and DSLAM</h3>

- **Components:**
    - **Filters:** Separate voice and data communications.
    - **DSLAM (Digital Subscriber Line Access Multiplexer):** Packetizes data to be sent to the Internet.

<h3>Other DSL Technologies</h3>

- **SDSL (Symmetric DSL):**
    - Provides equal bandwidth for both upstream and downstream.
    - Uses echo cancellation to create full-duplex transmission over a single twisted pair.
- **HDSL (High Bit-Rate DSL):**
    - Developed as an alternative to T1 lines.
    - Operates over longer distances without repeaters.
- **VDSL (Very High Bit-Rate DSL):**
    - Uses coaxial, fiber-optic, or twisted-pair cable for short distances (300 ~ 1800m).
    - Offers upstream rates of 1.5-2.5 Mbps and downstream rates of 50-55 Mbps.

<h3>Cable Modem</h3>

- **Traditional Cable Network:**
    - Cable TV bandwidth up to 750 MHz using coaxial cable.
    - 6 MHz per channel using Frequency Division Multiplexing (FDM).
    - Communication is traditionally unidirectional.

<h3>Figure 3.29 Cable Bandwidth</h3>

- **Data Bands:**
    - **Downstream Data Band:**
        - Standard 27 Mbps.
        - Modulation: 64-QAM (6 bits/baud).
    - **Upstream Data Band:**
        - Theoretical data rate up to 12 Mbps.
        - Modulation: QPSK (2 bits/baud).

<h3>Figure 3.30 Cable Modem Configuration</h3>

<h3>T Lines and SONET</h3>

- **T Lines:**
    - Standard digital telephone carriers designed originally to multiplex voice.
    - Commercially available in data rates like T-1 (1.544 Mbps) and T-3.
- **SONET (Synchronous Optical Network):**
    - Advantages include efficient multiplexing, higher network reliability, overhead for operations and maintenance, and cost-effective realization of new network architectures.

<h3>Point-to-Point Protocol (PPP)</h3>

- **Purpose:**
    - Manages the transfer of data over point-to-point links.
- **Components:**
    - **LCP (Link Control Protocol):**
        - Responsible for establishing, maintaining, and configuring the link.
    - **NCP (Network Control Protocol):**
        - Allows PPP to carry data from different network layer protocols (e.g., IP, IPX).

---

<h3>3.4 Switched WANs</h3>

- **Definition:**
    - A wide area network that covers a large area and provides access at several points to users.
    - Consists of a mesh of point-to-point networks connecting switches.
- **Switches:**
    - Multi-port connectors that allow the connection of several inputs and outputs.

<h3>X.25</h3>

- **Overview:**
    - An older packet-switching wide area network.
    - Used as a public network to connect individual computers or LANs.
    - Provides end-to-end service using virtual circuits.

<h3>Frame Relay</h3>

- **Advantages:**
    - High data rates (up to T-3 lines).
    - Low cost due to mesh topology connections.
    - Efficient for bursty data; provides bandwidth on demand.
    - Less overhead by not providing error checking and acknowledgment at the data link layer.

<h3>X.25 vs. Frame Relay</h3>

<h3>ATM (Asynchronous Transfer Mode)</h3>

- **Features:**
    - Low-cost design.
    - Supports existing telecommunication hierarchies.
    - Connection-oriented system to ensure accuracy and predictable delivery.
    - Moves some software functions to hardware to increase data rates.
- **Cell Network:**
    - Uses small, fixed-size cells as the basic unit of data exchange.

<h3>Figure 3.35 ATM Layers</h3>

- **AAL Types:**
    - **AAL1:** For Constant Bit Rate (CBR) services like real-time voice and video.
    - **AAL2:** For Variable Bit Rate (VBR) services like compressed voice and video.
    - **AAL5:** For connectionless packet protocols (e.g., IP datagrams).

---

<h3>3.5 Connecting Devices</h3>

- **Purpose:**
    - To connect LANs and WANs together.
- **Types of Devices:**
    - **Repeaters (or Hubs):** Operate at the physical layer.
    - **Bridges (or Two-Layer Switches):** Operate at the physical and data link layers.
    - **Routers (or Three-Layer Switches):** Operate at the network layer.

<h3>Figure 3.40 Connecting Devices</h3>

<h3>Repeaters and Hubs</h3>

- **Function:**
    - Connect segments of a LAN.
    - Regenerate signals to extend the network range.
- **Characteristics:**
    - Physical layer devices.
    - No filtering capability; forward every bit.

<h3>Figure 3.41 Repeater or Hub</h3>

<h3>Bridges</h3>

- **Function:**
    - Operate at both the physical and data link layers.
    - Regenerate signals and check MAC addresses.
    - Use a table for filtering decisions.
- **Characteristics:**
    - Do not change the physical (MAC) addresses in a frame.

<h3>Routers</h3>

- **Function:**
    - Operate at the physical, data link, and network layers.
    - Connect independent LANs or WANs to create an internetwork.
    - Change the physical addresses in a packet as needed.
- **Characteristics:**
    - Enable the creation of internetworks (internets) by connecting different networks.

<h3>Figure 3.44 Routing Example</h3>