##############################################################################
Chapter 9 WIFI Web Server
##############################################################################

Project 9.1 WIFI Web Servers LED
************************************************

Component List
============================================

.. table::
    :align: center
    :class: table-line
    :width: 80%

    +-------------------------------+----------------+
    | Freenove ESP32 S3 Display x 1 | USB cable x1   |
    |                               |                |
    | |Chapter01_07|                | |Chapter01_08| |
    +-------------------------------+----------------+

.. |Chapter01_07| image:: ../_static/imgs/1_Serial/Chapter01_07.png
.. |Chapter01_08| image:: ../_static/imgs/1_Serial/Chapter01_08.png

Component Knowledge
============================================

Wi-Fi
--------------------------------------------

Wi-Fi is a wireless LAN (WLAN) technology compliant with the IEEE 802.11 standard, enabling devices to transmit data or connect to the internet via radio waves within short-range coverage (typically up to tens of meters). In embedded systems, Wi-Fi modules provide wireless communication capabilities, allowing devices to connect to routers, access cloud services, or interact with other devices. 

Its core features include:

- Wireless connectivity (eliminating the need for physical cabling)

- Moderate to high-speed data transfer (depending on protocol versions such as 802.11n/ac)

- Secure communication (ensured by encryption protocols like WPA2/WPA3)

In embedded development, Wi-Fi is one of the key technologies for enabling IoT (Internet of Things) device connectivity.

Web
--------------------------------------------

The Web (World Wide Web) is an internet-based information system that integrates global resources through hypertext links. In the embedded field, Web technology refers to devices equipped with lightweight built-in web servers, allowing users to remotely access the device interface via browsers (such as Chrome or Edge). By entering the device's IP address, users can open an interactive page to perform functions like status monitoring, parameter configuration, or firmware upgrades. Its core value lies in cross-platform compatibility (no need for dedicated software installation) and standardized protocols (HTTP/HTTPS), making it a mainstream solution for remote management of embedded devices.

HTML & CSS & JavaScript
--------------------------------------------

- **HTML (HyperText Markup Language)** is the standard language for structuring web pages. It uses tags to define page elements, forming the foundational framework. In embedded web interfaces, HTML describes the layout of components such as device status displays and configuration forms.  

- **CSS (Cascading Style Sheets)** controls the visual presentation of web pages, including colors, fonts, spacing, and responsive layouts. Through CSS rules, developers style HTML elements into intuitive interactive interfaces. The combination of HTML and CSS enables the creation of lightweight device control pages without complex graphics libraries, reducing resource overhead in embedded systems.  

- **JavaScript (a scripting language)** adds dynamic behavior and interaction logic to web pages. In embedded web interfaces, JavaScript plays a crucial role: it responds to user actions and enables asynchronous communication with the device backend through technologies like **AJAX** or **WebSocket**. This allows the webpage to fetch real-time device status data, update displays without refreshing, and send control commands or configuration parameters—delivering a smooth and efficient remote management experience.

Circuit
============================================

Connect Freenove ESP32 -S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_00.png
    :align: center

Sketch
============================================

Next, we download the code to Freenove_ESP32_S3_Display to test. Open **“Sketch_09.1_WiFi_Web_Servers_LED”** folder under **“Freenove_ESP32_S3_Display\\Sketches”** and double-click **“Sketch_09.1_WiFi_Web_Servers_LED.ino”**.

:combo:`red font-bolder:Important Note: Before upload the code, please ensure that the Wi-Fi SSID and Password are correctly configured in the code, and that the Wi-Fi network to connect is 2.4GHz.`

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 11-12
    :dedent:

Sketch_09.1_WiFi_Web_Servers_LED
-------------------------------------------

The following is the program code:

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :dedent:

Code Explanation
-------------------------------------------

Include necessary header files.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 7-7
    :dedent:

Configure WiFi SSID and password.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 11-12
    :dedent:

Define pins for the RGB LED.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 21-23
    :dedent:

Initialize the configuration related to RGB LED.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 39-42
    :dedent:

Connect to WIFI.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 60-67
    :dedent:

Check if there are any new clients connected to the server.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 78-78
    :dedent:

Parse the URL command and control the corresponding LED on and off.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 96-121
    :dedent:

Use CSS styles to enhance the visual appeal of web interfaces.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 140-153
    :dedent:

Generate the HTML contents to control the LED.

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 159-175
    :dedent:

Disconnect from the client and print the disconnection information in the serial monitor

.. literalinclude:: /freenove_Kit/Sketches/Sketch_09.1_WiFi_Web_Servers_LED/Sketch_09.1_WiFi_Web_Servers_LED.ino
    :linenos:
    :language: C
    :lines: 202-204
    :dedent:

Input correct WiFi(2.4GHz) SSID and password.

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_01.png
    :align: center

Click **“Upload”** to upload the code to Freenove ESP32 Display.

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_02.png
    :align: center

When the serial monitor prints the following information, it means the network connection is successful. Use a mobile phone or computer browser to open the IP address printed by the serial monitor.

:combo:`red font-bolder:Please note: If it keeps printing dots, please confirm whether the WiFi is in the 2.4G band.`

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_03.png
    :align: center

The following screen will be displayed in the computer's browser, where you can control the color of the RGB light by clicking on the three cards.

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_04.png
    :align: center

On the phone web browser, you'll see the following contents. The color of the RGB light can be controlled by clicking on the three cards.

.. image:: ../_static/imgs/9_WIFI_Web_Server/Chapter09_05.png
    :align: center

Reference
---------------------------

.. py:function:: server.begin()

    This function starts the server to monitor the port.

.. py:function:: server.available()	

    This function is used to detect and return the connected client object.