import os
from PIL import Image

def convert_images_to_webp(folder):
    """
    Converts all images in a folder and its subfolders to WEBP format.

    Args:
        folder (str): Path to the folder containing images.
    """
    for root, _, files in os.walk(folder):
        for file in files:
            if file.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.tiff')):
                file_path = os.path.join(root, file)
                webp_path = os.path.splitext(file_path)[0] + ".webp"

                # Read the image
                image = cv2.imread(file_path)
                if image is not None:
                    cv2.imwrite(webp_path, image, [cv2.IMWRITE_WEBP_QUALITY, 90])
                    print(f"Converted: {file_path} -> {webp_path}")

if __name__ == "__main__":
    # Specify the folder containing the images
    root_folder = "/path/to/your/folder"
    convert_images_to_webp(root_folder)