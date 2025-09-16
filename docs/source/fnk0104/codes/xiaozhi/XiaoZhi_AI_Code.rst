##############################################################################
XiaoZhi AI Code
##############################################################################

Visual Studio Code
******************************

Windows
=============================

First, download Visual Studio Code by visiting https://code.visualstudio.com/Download. Choose the appropriate version for your operating system, then download and install it.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi00.png
    :align: center

Double-click the downloaded .exe file to run it.

Check the box for "I accept the agreement."

Then click Next.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi01.png
    :align: center

The installation location can be left as the default or changed to a desired path. After that, proceed by clicking Next repeatedly.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi02.png
    :align: center

On this screen, verify that "Add to PATH" is selected. If unchecked, enable it. Proceed by clicking Next repeatedly to finish the installation.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi03.png
    :align: center

The installation is now complete, as shown in the image below.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi04.png
    :align: center

Mac
============================

Typically, MacOS comes with Visual Studio Code pre-installed. If your computer does not have it, please install it first.

Visit https://code.visualstudio.com and click "Download for macOS”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi05.png
    :align: center

Double click to run the program.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi06.png
    :align: center

Linux
============================

If your computer does not have Visual Studio Code, please install it first.

Visit https://code.visualstudio.com and click ".deb”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi07.png
    :align: center

Open the downloaded“code_xxx.deb” file.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi08.png
    :align: center

Click “Install” to install Visual Studio Code.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi09.png
    :align: center

Wait for the installation to complete. Once finished, it should look like the image below.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi10.png
    :align: center

Click Show Apps and you can see the Visual Studio Code is in the system.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi11.png
    :align: center

Installing ESP-IDF V5.3.2 
************************************

Visual Studio Code is a versatile code editor. To program with the ESP-IDF SDK, we need to install the ESP-IDF extension for it.

Open Visual Studio Code.

Click on the menu bar: File -> Preferences -> Extensions.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi12.png
    :align: center

Mac OS: Click “Code” -> ”Preferences” -> ”Extensions” on the menu bar.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi13.png
    :align: center

Search for "ESP-IDF" in the extension bar, select the correct result from the list, then click the Install button to proceed.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi14.png
    :align: center

The ESP-IDF extension icon will now appear in the left sidebar - click it to continue.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi15.png
    :align: center

Scroll down with your mouse, locate and click on the "Advanced" option.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi16.png
    :align: center

Click the first option: "Configure ESP-IDF Extension”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi17.png
    :align: center

Select "EXPRESS" on the right.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi18.png
    :align: center

.. note::
    
    If you're using macOS or Ubuntu, please complete the necessary preparations as prompted before proceeding with installation.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi19.png
    :align: center

1. Check the box for "Show all ESP-IDF tags"

2. Select "v5.3.2 (release version)" from the dropdown

3. Choose your desired installation path for the ESP-IDF environment

4. Click "Install" to begin the setup

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi20.png
    :align: center

The process will complete automatically.

If it failed, locate your chosen ESP-IDF directory, remove the failed installation folder and install it again.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi21.png
    :align: center

This step may take a while, so please ensure you have a stable and fast internet connection.

The complete installation is as shown below.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi22.png
    :align: center

For more about ESP-IDF, please refer to

https://docs.espressif.com/projects/vscode-esp-idf-extension/en/latest/installation.html

Code Downloading
============================

Windows
-----------------------------------

Open a browser on your computer and enter “https://github.com/Freenove/xiaozhi-esp32”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi23.png
    :align: center

Click “Code” -> “Download ZIP” to download the code to your computer.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi24.png
    :align: center

Extract the downloaded zip file to your computer. Rename the decompressed folder to "xiaozhi-esp32".

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi25.png
    :align: center

Mac
-----------------------------------

Open the terminal and download the code with the git command.

.. code-block:: console
    
    git clone https://github.com/Freenove/xiaozhi-esp32.git

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi26.png
    :align: center

Linux
-----------------------------------

Open the terminal and download the code with the git command.

git clone https://github.com/Freenove/xiaozhi-esp32.git

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi27.png
    :align: center

Configure Code Environment
====================================

**Extract the downloaded ZIP file.**

On Visual Studio Code, click “File” -> “Open Folder…”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi28.png
    :align: center

Select the **xiaozhi-esp32** folder. Here, the interface of the Windows system is taken as an example. The operation of the mac system is similar to that of Linux.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi29.png
    :align: center

Check the box “Trust the authors of all files in the parent folder “Downloads” and select “Yes, I trust the authors”.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi30.png
    :align: center

Please note: A pop-up notification will appear in the lower-right corner. Click 'Generate comple_commands.json', and it will download the corresponding component module code based on the file."

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi31.png
    :align: center

Component installation may take some time. Please wait and avoid other operations. A completion notification will appear in the lower-right corner once finished.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi32.png
    :align: center

Connect the ESP32-S3 to your computer using a USB cable, making sure to plug it into the correct Type-C port (do not use the wrong connector)

Click on **'COMx'** in the bottom-left corner to display all available COM ports on your computer. Locate and select the entry labeled 'ESP32-S3'.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi33.png
    :align: center

Click the **'ESP32'** button in the bottom-left corner to display all available ESP32 models, then select **'ESP32-S3'** from the list." 

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi34.png
    :align: center

From the new selection menu, choose **'ESP32-S3 Chip (via ESP-PROG) - ESP32-S3 debugging via ESP-PROG Board...'**

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi35.png
    :align: center

Wait until it shows **“Target ESP32S3 Set Successfully”** at the bottom right.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi36.png
    :align: center

Click “SDK Configuration Editor (menuconfig)” at the bottom. 

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi37.png
    :align: center

On the new interface, click 'Serial flasher config' and verify that the settings match the configuration shown in the image below.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi38.png
    :align: center

Click “Partition Table” and verify that the settings match the configuration shown in the image below.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi39.png
    :align: center

Click **“Xiao Assistant”** and verify that the settings match the configuration shown in the image below. 

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi40.png
    :align: center

Click **“Load Multiple Wake Words”** and check the boxes for 'Hi, ESP' and 'Hi, Lily' (and other desired options).

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi41.png
    :align: center

Finally, click “Save” to store your configuration. A success message will appear at the bottom upon completion.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi42.png
    :align: center

Code Compilation
===================================

Before compiling, make sure all aforementioned configurations are correct. Click the 'Full Clean' button (bottom toolbar) to reset build cache. 

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi43.png
    :align: center

Click 'Build Project' at the bottom to start compiling the entire project. The first compilation may take longer - please wait patiently until the success message appears in the output panel.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi44.png
    :align: center

Click 'Flash Device' at the bottom to start uploading the code to your ESP32-S3 module.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi45.png
    :align: center

From the new options menu, select **'UART'** and wait for the code upload to complete. 

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi46.png
    :align: center

Upon seeing the message 'Flash has finished. You can monitor your device with "ESP-IDF: Monitor command"', this indicates you have successfully uploaded XiaoZhi AI's firmware to the ESP32-S3 module.

.. image:: ../_static/imgs/XiaoZhi_AI_Code/xiaozhi47.png
    :align: center

At this point, the compilation is complete and you're ready for secondary development.