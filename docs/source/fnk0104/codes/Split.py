import os
import shutil

# --------------- User-defined configuration area ---------------

# Define the base path to operate on
base_path = "./"  # Please replace with your actual path

# Define the names of the original and new folders
main_folder = "MAIN"
new_folder = "MAIN_NonTouch"

# Define a set of files to be deleted
files_to_delete = {
    '11_TFT_Touch.rst',
    '12_TFT_Touch_Drawing.rst',
    '14_LVGL_Picture.rst',
    '15_LVGL_Timer.rst',
    '16_Lvgl_RGB.rst',
    '17_LVGL_Music.rst',
    '18_LVGL_Multifunctionality.rst'
}

# Define a dictionary for files to be renamed
files_to_rename = {
    "13_LVGL.rst": "11_LVGL.rst",
    "19_LVGL_Arduino.rst": "12_LVGL_Arduino.rst"
}

# Define a dictionary for content to be replaced in .rst files
content_to_replace = {
    "Chapter 13": "Chapter 11",
    "Project 13.1": "Project 11.1",
    "Sketch_13.1": "Sketch_11.1",
    "/Sketch_11.1_LVGL": "/Sketch_13.1_LVGL",
    "Chapter 19": "Chapter 12",
    "Project 19.1": "Project 12.1",
    "Sketch_19.1": "Sketch_12.1",
    "/Sketch_12.1_Lvgl_Arduino": "/Sketch_19.1_Lvgl_Arduino",
}

# --------------- Script execution area ---------------

# Construct the full folder paths
main_folder_path = os.path.join(base_path, main_folder)
new_folder_path = os.path.join(base_path, new_folder)

try:
    # Step one: Delete the existing MAIN_NonTouch folder if it exists
    if os.path.exists(new_folder_path):
        shutil.rmtree(new_folder_path)
        print(f"Successfully deleted old folder: {new_folder_path}")

    # Step two: Copy the MAIN folder and rename it to MAIN_NonTouch
    shutil.copytree(main_folder_path, new_folder_path)
    print(f"Successfully copied folder '{main_folder}' to '{new_folder}'")

    # Step three: Delete the specified files in the new folder
    for filename in files_to_delete:
        file_path_to_delete = os.path.join(new_folder_path, filename)
        if os.path.exists(file_path_to_delete):
            os.remove(file_path_to_delete)
            print(f"Successfully deleted file: {file_path_to_delete}")
        else:
            print(f"Warning: The file to be deleted does not exist: {file_path_to_delete}")
            
    # Step four: Rename the files inside the new folder
    for old_name, new_name in files_to_rename.items():
        old_file_path = os.path.join(new_folder_path, old_name)
        new_file_path = os.path.join(new_folder_path, new_name)
        if os.path.exists(old_file_path):
            os.rename(old_file_path, new_file_path)
            print(f"Successfully renamed '{old_name}' to '{new_name}'")
        else:
            print(f"Warning: The file to be renamed does not exist: {old_file_path}")
            
    # Step five: Replace the content of all .rst files in the new folder
    for item in os.listdir(new_folder_path):
        if item.endswith(".rst"):
            file_path = os.path.join(new_folder_path, item)
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    file_content = file.read()

                original_content = file_content
                for find_str, replace_str in content_to_replace.items():
                    file_content = file_content.replace(find_str, replace_str)
                
                if original_content != file_content:
                    with open(file_path, 'w', encoding='utf-8') as file:
                        file.write(file_content)
                    print(f"Successfully replaced content in file '{item}'")
            except Exception as e:
                print(f"An error occurred while processing file '{item}': {e}")

    print("\nScript execution completed!")

except FileNotFoundError:
    print(f"Error: The source folder '{main_folder_path}' does not exist.")
except Exception as e:
    print(f"An error occurred during execution: {e}")