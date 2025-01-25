import os
import cv2

def create_video_from_images(image_folder, output_video, frame_rate):
    """
    Create a video from a sequence of images in a folder.

    :param image_folder: Path to the folder containing images
    :param output_video: Path to the output video file
    :param frame_rate: Frame rate of the video (frames per second)
    """
    # Get a sorted list of image file names
    images = sorted([img for img in os.listdir(image_folder) if img.endswith((".png", ".jpg", ".jpeg"))])

    if not images:
        print(f"No images found in the folder: {image_folder}")
        return

    # Get the dimensions of the first image
    first_image_path = os.path.join(image_folder, images[0])
    first_image = cv2.imread(first_image_path)
    height, width, layers = first_image.shape

    # Define the codec and create VideoWriter object
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # Use 'XVID' for .avi output
    video_writer = cv2.VideoWriter(output_video, fourcc, frame_rate, (width, height))

    for image_name in images:
        image_path = os.path.join(image_folder, image_name)
        frame = cv2.imread(image_path)
        if frame is None:
            print(f"Warning: Unable to read {image_name}, skipping.")
            continue
        video_writer.write(frame)

    # Release the video writer
    video_writer.release()
    print(f"Video saved as {output_video}")

def process_subfolders(root_folder, frame_rate):
    """
    Walk through the root folder and create a video for images in each subfolder.

    :param root_folder: Path to the root folder
    :param frame_rate: Frame rate of the video (frames per second)
    """
    for subdir, _, _ in os.walk(root_folder):
        # Skip the root folder itself
        if subdir == root_folder:
            continue

        print(f"Processing folder: {subdir}")
        output_video = os.path.join(subdir, "output_video.mp4")
        create_video_from_images(subdir, output_video, frame_rate)

# Example usage
if __name__ == "__main__":
    root_folder = "./images"  # Replace with your root folder path
    frame_rate = 5             # Frame rate set to 5 fps

    process_subfolders(root_folder, frame_rate)
