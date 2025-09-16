##############################################################################
Chapter 1 Serial
##############################################################################

Project 1.1 SerialRW
*************************************

Related Knowledge
====================================

Serial and parallel communication
-----------------------------------

Serial communication uses one data cable to transfer data one bit by another in turn, while parallel communication means that the data is transmitted simultaneously on multiple cables. Serial communication takes only a few cables to exchange information between systems, which is especially suitable for computers to computer, long distance communication between computers and peripherals. Parallel communication is faster, but it requires more cables and higher cost, so it is not appropriate for long distance communication.

.. image:: ../_static/imgs/1_Serial/Chapter01_00.png
    :align: center

Serial communication
=====================================

Serial communication generally refers to the Universal Asynchronous Receiver/Transmitter (UART), which is commonly used in electronic circuit communication. It has two communication lines, one is responsible for sending data (TX line) and the other for receiving data (RX line). The serial communication connections of two devices use is as follows:

.. image:: ../_static/imgs/1_Serial/Chapter01_01.png
    :align: center

Before serial communication starts, the baud rate in both sides must be the same. Only use the same baud rate can the communication between devices be normal. The baud rates commonly used are 9600 and 115200.

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

Circuit
====================================

Connect Freenove ESP32 S3 Display to the computer with USB cable.

.. image:: ../_static/imgs/Preface/Preface09.png
    :align: center

Sketch
====================================

Open **“Sketch_01.1_SerialRW”** folder under **“Freenove_ESP32_S3_Display\\Sketches”** and double-click **“Sketch_01.1_SerialRW.ino”**.

Sketch_01.1_SerialRW
-------------------------------------

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_01.1_SerialRW/Sketch_01.1_SerialRW.ino
    :linenos:
    :language: C
    :dedent:

Code Explanation
-------------------------------------

Set the baud rate to 115200.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_01.1_SerialRW/Sketch_01.1_SerialRW.ino
    :linenos:
    :language: C
    :lines: 11-11
    :dedent:

Determine whether there is data in the serial port buffer.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_01.1_SerialRW/Sketch_01.1_SerialRW.ino
    :linenos:
    :language: C
    :lines: 14-14
    :dedent:

Receive serial port data and save it in the inputString string.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_01.1_SerialRW/Sketch_01.1_SerialRW.ino
    :linenos:
    :language: C
    :lines: 20-21
    :dedent:

Select Tools -> Board -> esp32 -> ESP32S3 Dev Module. 

.. image:: ../_static/imgs/1_Serial/Chapter01_02.png
    :align: center

After connecting the Freenove Media Kit for ESP32-S3, the system will assign a serial communication port named in the format 'COMx' (where 'x' is a numeric ID that may vary across computers). You must select the correct port under Tools → Port.

.. note::
    
    :combo:`red font-bolder:COM1 is typically NOT the port used by the Freenove Media Kit for ESP32-S3.`

.. image:: ../_static/imgs/1_Serial/Chapter01_03.png
    :align: center

Enable the "USB CDC On Boot" feature.

.. image:: ../_static/imgs/1_Serial/Chapter01_04.png
    :align: center

The purpose of this code is to display data on the serial monitor. Click “Upload” to upload the code to Freenove ESP32 S3 Display.

.. image:: ../_static/imgs/1_Serial/Chapter01_05.png
    :align: center

After downloading the code, open the serial port monitor, and set the baud rate to 115200, input any data in the messages bard and press Enter key, Freenove ESP32 S3 Display will print the received data.

.. image:: ../_static/imgs/1_Serial/Chapter01_06.png
    :align: center

Reference
-------------------------------

.. py:function:: int available() 	
    
    Serial.available() checks the number of bytes currently available to read in the Serial receive buffer. It returns the number of bytes available (int type), or 0 if the buffer is empty.

.. py:function:: int read ()	

    Serial.read() reads one byte of data from the Serial receive buffer and returns it as an int. If no data is available to read, it returns -1.