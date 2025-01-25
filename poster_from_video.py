import os
%pip install opencv-python
import cv2

def extract_first_frame(video_path, output_folder):
    # Create a VideoCapture object
    cap = cv2.VideoCapture(video_path)
    
    # Read the first frame
    success, frame = cap.read()
    
    if success:
        # Get the video filename without extension
        video_name = os.path.basename(video_path).split('.')[0]
        # Create the output image path
        output_path = os.path.join(output_folder, f'{video_name}_poster.jpg')
        # Save the first frame as an image
        cv2.imwrite(output_path, frame)
        print(f"Poster saved: {output_path}")
    else:
        print(f"Failed to read video: {video_path}")
    
    # Release the VideoCapture object
    cap.release()

def process_videos(input_folder, output_folder):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)
    
    # Iterate through all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith(('.mp4', '.avi', '.mkv', '.mov')):  # Add more video extensions if needed
            video_path = os.path.join(input_folder, filename)
            extract_first_frame(video_path, output_folder)
        else:
            print(f"Skipped non-video file: {filename}")

if __name__ == "__main__":
    # Define the input and output folders
    input_folder = "./"
    output_folder = "./posters"

    # Process the videos
    process_videos(input_folder, output_folder)