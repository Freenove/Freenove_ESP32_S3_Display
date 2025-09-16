##############################################################################
Chapter 17 LVGL Music
##############################################################################

Project 17.1 LVGL Music
**************************************

Component List 
==================================

.. table::
    :align: center
    :class: table-line
    :width: 80%

    +-------------------------------+----------------+
    | Freenove ESP32 S3 Display x 1 | USB cable x1   |
    |                               |                |
    | |Chapter07_00|                | |Chapter07_01| |
    +-------------------------------+----------------+
    | Speaker x1                                     |
    |                                                |
    | |Chapter07_02|                                 |
    +------------------------------------------------+

.. |Chapter07_00| image:: ../_static/imgs/7_Music/Chapter07_00.png
.. |Chapter07_01| image:: ../_static/imgs/7_Music/Chapter07_01.png
.. |Chapter07_02| image:: ../_static/imgs/7_Music/Chapter07_02.png

.. note::
    
    :combo:`red font-bolder:This kit does not include SD card, or SD card reader. Please buy them yourself!`

Circuit
=================================

Connect Freenove ESP32-S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_00.png
    :align: center

Connect Freenove ESP32-S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_01.png
    :align: center

Sketch
================================

Open **“Sketch_17.1_Lvgl_Music”** folder under **“Freenove_ESP32_S3_Display\\Sketches”** and double-click **“Sketch_17.1_Lvgl_Music.ino”**.

Sketch_17.1_Lvgl_Music
------------------------------------------

The following is the program code:

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :dedent:

Code Explanation
-------------------------------------------

Include the header files.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 7-13
    :dedent:

Define the pins.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 7-13
    :dedent:

Set the baud rate to 115200

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 50-50
    :dedent:

Initialize configuration.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 53-59
    :dedent:

Create and load the interface.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 66-67
    :dedent:

LVGL task processor.

.. literalinclude:: /freenove_Kit/Touch/Sketches/Sketch_17.1_Lvgl_Music/Sketch_17.1_Lvgl_Music.ino
    :linenos:
    :language: C
    :lines: 73-73
    :dedent:

Insert the SD card to the card reader and plug them to the computer. Copy the **Music** folder under the **Freenove_ESP32_S3_Display\\Sketches\\Sketch_17.1_Lvgl_Music** directory to the root directory of the SD card.

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_02.png
    :align: center

It is necessary to change the settings in Arduino IDE before clicking the Uploading button, as shown below.

.. caution::
    
    :combo:`red font-bolder:Incorrect settings will result in compilation error or uploading failure. To achieve desired result, please configure exactly the same as below.`

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_03.png
    :align: center

Click **“Upload”** to upload the code to Freenove ESP32 Display. Set the baud rate to 115200.

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_04.png
    :align: center

.. image:: ../_static/imgs/17_LVGL_Music/Chapter17_05.png
    :align: center

.. note::
    
    :combo:`red font-bolder:If the screen flickers during playback, it may be due to insufficient power supply. You can try powering with a battery.`