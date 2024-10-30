from PIL import Image

# Define the ASCII characters in descending order of intensity
ASCII_CHARS = "@%#*+=-:. "

def scale_image(image, new_width=100):
    """Resize the image while maintaining aspect ratio."""
    width, height = image.size
    aspect_ratio = height / width
    new_height = int(aspect_ratio * new_width * 0.55)  # 0.55 adjusts for font aspect ratio
    return image.resize((new_width, new_height))

def convert_to_grayscale(image):
    """Convert the image to grayscale."""
    return image.convert("L")

def map_pixels_to_ascii_chars(image, range_width=25):
    """Map each pixel to an ASCII char based on its intensity."""
    pixels = image.getdata()
    ascii_str = "".join([ASCII_CHARS[pixel // range_width] for pixel in pixels])
    return ascii_str

def convert_image_to_ascii(image_path, new_width=100):
    """Main function to convert an image to ASCII art."""
    try:
        image = Image.open(image_path)
    except Exception as e:
        print(f"Unable to open image: {e}")
        return

    image = scale_image(image, new_width)
    image = convert_to_grayscale(image)

    ascii_str = map_pixels_to_ascii_chars(image)
    img_width = image.width
    ascii_img = "\n".join([ascii_str[i:i + img_width] for i in range(0, len(ascii_str), img_width)])

    return ascii_img

if __name__ == "__main__":
    # Provide the path to your image
    image_path = input("Enter the path to the image: ")
    ascii_art = convert_image_to_ascii(image_path)

    if ascii_art:
        print("\nASCII Art:\n")
        print(ascii_art)

        # Save the output to a file
        with open("ascii_art.txt", "w") as f:
            f.write(ascii_art)
        print("\nASCII art saved to 'ascii_art.txt'.")
