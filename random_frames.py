import os
import cv2
import random

def extract_random_frames(input_folder, output_folder, frames_range=(5, 10)):
    """
    Extracts 5-10 random frames from each .mp4 file in the input folder and saves them to a folder named after the video.

    Args:
        input_folder (str): Path to the folder containing .mp4 files.
        output_folder (str): Path to the folder where extracted frames will be saved.
        frames_range (tuple): Range of random frames to extract, default is between 5 and 10.
    """
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for filename in os.listdir(input_folder):
        if filename.endswith('.mp4'):
            video_path = os.path.join(input_folder, filename)
            video_name = os.path.splitext(filename)[0]
            video_output_folder = os.path.join(output_folder, video_name)

            if not os.path.exists(video_output_folder):
                os.makedirs(video_output_folder)

            # Open the video file
            cap = cv2.VideoCapture(video_path)
            frame_count = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

            if frame_count == 0:
                print(f"Skipping {filename} due to zero frames.")
                cap.release()
                continue

            # Determine the number of frames to extract
            num_frames = 10
            selected_frames = sorted(random.sample(range(frame_count), num_frames))

            print(f"Processing {filename}: extracting {num_frames} frames.")

            current_frame_idx = 0
            count =  1
            for frame_idx in selected_frames:
                while current_frame_idx <= frame_idx:
                    ret, frame = cap.read()
                    if not ret:
                        break
                    current_frame_idx += 1

                if ret:
                    frame_filename = os.path.join(video_output_folder, f"image_{count}.jpg")
                    count += 1
                    cv2.imwrite(frame_filename, frame)

            cap.release()

if __name__ == "__main__":
    input_folder = "./"
    output_folder = "./frames"

    extract_random_frames(input_folder, output_folder)
