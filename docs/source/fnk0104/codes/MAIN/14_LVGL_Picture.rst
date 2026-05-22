##############################################################################
Chapter 14 LVGL Picture
##############################################################################

Project 14.1 LVGL Picture
******************************************************************************

Component List 
==============================================================================

.. table::
    :align: center
    :class: table-line

    +-------------------------------+----------------+
    | Freenove ESP32-S3 Display x 1 | USB cable x1   |
    |                               |                |
    | |Chapter11_04|                | |Chapter11_07| |
    +-------------------------------+----------------+

.. |Chapter11_04| image:: ../_static/imgs/11_TFT_Touch/Chapter11_04.png
.. |Chapter11_07| image:: ../_static/imgs/11_TFT_Touch/Chapter11_07.png

Circuit
==============================================================================

Before connecting the USB cable, insert the SD card into the SD card slot on the back of the ESP32-S3.

:combo:`red font-bolder:Please note that this kit does not include SD card and card reader; please buy them yourself.`

.. image:: ../_static/imgs/6_SD_Card/Chapter06_13.png
    :align: center

Connect Freenove ESP32-S3 to the computer using the USB cable. 

.. image:: ../_static/imgs/11_TFT_Touch/Chapter11_05.png
    :align: center

**If you have any concerns, please feel free to contact us via** support@freenove.com

Sketch
==========================================

Open **“Sketch_14.1_Lvgl_Picture”** folder under **“Freenove_ESP32_S3_Display\\Tutorial_With_Touch\\Sketches”** and double-click **“Sketch_14.1_Lvgl_Picture.ino”**. 

Sketch_14.1_Lvgl_Picture
------------------------------------------

The following is the program code:	

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :dedent:

Code Explanation
------------------------------------------

Include the header files.

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 10-12
    :dedent:

Define the pins.

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 14-28
    :dedent:

Set the baud rate to 115200

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 34-34
    :dedent:

Initialize configuration.

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 37-38
    :dedent:

Create and load the interface.

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 51-52
    :dedent:

LVGL Task Processor

.. literalinclude:: /freenove_Kit/Tutorial_With_Touch/Sketches/Sketch_14.1_Lvgl_Picture/Sketch_14.1_Lvgl_Picture.ino
    :linenos:
    :language: C
    :lines: 59-59
    :dedent:

Copy the Picture folder under the **Freenove_ESP32_S3_Display\\Tutorial_With_Touch\\Sketches\\Sketch_14.1_Lvgl_Picture** directory to the SD card root directory.

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_01.png
    :align: center

Click **“Upload”** to upload the code to Freenove ESP32 Display. Set the baud rate to 115200

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_02.png
    :align: center

Custom image display
------------------------------------

You can customize the image displayed on the display according to your personal preferences.

First, open **Freenove_ESP32_S3_Display\\Sketches\\Sketch_14.1_Lvgl_Picture\\Freenove Image Tool.exe**

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_03.png
    :align: center

Click **“Add File”**

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_04.png
    :align: center

Select any image you like.

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_05.png
    :align: center

The image files from your folder will now appear in the Pending File List.

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_06.png
    :align: center

Click “Select…” to choose the image saving location.

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_07.png
    :align: center

Select BMP for the format, set the resolution to 240x240.

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_08.png
    :align: center

Wait for the progress bar to complete.

Copy or replace the generated image to the folder corresponding to the Picture folder in the root directory of the SD card. 

.. image:: ../_static/imgs/14_LVGL_Picture/Chapter14_09.png
    :align: center