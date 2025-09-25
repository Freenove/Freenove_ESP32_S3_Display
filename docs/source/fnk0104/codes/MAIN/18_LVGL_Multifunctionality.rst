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

    +-------------------------------+----------------+
    | Freenove ESP32-S3 Display x 1 | USB cable x1   |
    |                               |                |
    | |Chapter11_04|                | |Chapter11_07| |
    +-------------------------------+----------------+
    | Speaker x1                                     |
    |                                                |
    | |Chapter07_02|                                 |
    +------------------------------------------------+

.. |Chapter11_04| image:: ../_static/imgs/11_TFT_Touch/Chapter11_04.png
.. |Chapter11_07| image:: ../_static/imgs/11_TFT_Touch/Chapter11_07.png
.. |Chapter07_02| image:: ../_static/imgs/7_Music/Chapter07_02.png

Circuit
=================================

Connect Freenove ESP32-S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/6_SD_Card/Chapter06_13.png
    :align: center

Connect Freenove ESP32-S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/11_TFT_Touch/Chapter11_05.png
    :align: center

Sketch
================================

Open **“Sketch_18.1_Lvgl_Multifunctionality”** folder under **“Freenove_ESP32_S3_Display\\Tutorial_With_Touch\\Sketches”** and double-click **“Sketch_18.1_Lvgl_Multifunctionality.ino”**.

Sketch_18.1_Lvgl_Multifunctionality
------------------------------------------

The following is the program code:

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_18.1_Lvgl_Multifunctionality/Sketch_18.1_Lvgl_Multifunctionality.ino
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