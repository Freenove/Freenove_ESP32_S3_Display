##############################################################################
Chapter 18 LVGL Multifunctionality
##############################################################################

Project 18.1 LVGL Multifunctionality
***************************************

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

Open **“Sketch_18.1_Lvgl_Multifunctionality”** folder under **“Freenove_ESP32_S3_Display\\Sketches”** and double-click **“Sketch_18.1_Lvgl_Multifunctionality.ino”**.

Sketch_18.1_Lvgl_Multifunctionality
------------------------------------------

The following is the program code:

.. literalinclude:: /freenove_Kit/Sketches/Sketch_18.1_Lvgl_Multifunctionality/Sketch_18.1_Lvgl_Multifunctionality.ino
    :linenos:
    :language: C
    :dedent:

It is necessary to change the settings in Arduino IDE before clicking the Uploading button, as shown below.

.. caution::

    :combo:`red font-bolder:Incorrect settings will result in compilation error or uploading failure. To achieve desired result, please configure exactly the same as below.`

.. image:: ../_static/imgs/18_LVGL_Multifunctionality/Chapter18_00.png
    :align: center

Click “Upload” to upload the code to Freenove ESP32 Display. Set the baud rate to 115200.

.. image:: ../_static/imgs/18_LVGL_Multifunctionality/Chapter18_01.png
    :align: center

.. image:: ../_static/imgs/18_LVGL_Multifunctionality/Chapter18_02.png
    :align: center