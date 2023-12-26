import os
import shutil
import time

def sort_files(download_path, main_folder_path):
    # Define file type categories and their corresponding extensions
    file_types = {
        'Csv': ['.csv'],
        'Images': ['.jpg', '.jpeg', '.png', '.gif', '.webp', '.avif'],
        'Videos': ['.mp4', '.avi', '.mov', '.webm', '.mkv'],
        'Documents': ['.doc', '.docx', '.pdf', '.txt', '.pptx', '.xlsx'],
        'Installers': ['.zip', '.dmg', '.gz'],
        'Programming': ['.py', '.ipynb', '.js', '.html', '.css', '.java', '.c', '.cpp', '.cs', '.sh', '.rb', '.php', '.go', '.sql']
    }

    # Create subfolders if they don't exist
    for category in file_types:
        os.makedirs(os.path.join(main_folder_path, category), exist_ok=True)

    # Move files to their respective folders
    for file in os.listdir(download_path):
        file_path = os.path.join(download_path, file)
        if os.path.isfile(file_path):
            ext = os.path.splitext(file)[1].lower()
            for category, extensions in file_types.items():
                if ext in extensions:
                    shutil.move(file_path, os.path.join(main_folder_path, category, file))
                    break

if __name__ == "__main__":
    download_path = r"/Users/jay/Downloads"
    main_folder_path = r"/Users/jay/Downloads/SortedFiles"

    # Run the sorting in a continuous loop
    while True:
        sort_files(download_path, main_folder_path)
        time.sleep(10)  # Wait for 10 seconds before checking again
