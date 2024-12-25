from PIL import Image

import random


def open_image(image_path):
  try:
    image = Image.open(image_path)
    return image
  except Exception as e:
    print(f"Error loading image: {e}")
    return None

def get_pixel_color(image, x, y):
  try:
    r, g, b = image.getpixel((x, y))
    print(f"test(Color({r},{g},{b}), Pos({x},{y}));")
  except Exception as e:
    print(f"Error accessing pixel at ({x}, {y}): {e}")


def get_pixel_similar(image, x, y):
  try:
    r,g,b = image.getpixel((x, y))
    tolerance = 255 * 0.1  # 10% tolerance (255 - (255 * 0.9))
    r = random.randint(max(0, int(r - tolerance)), min(255, int(r + tolerance)))
    g = random.randint(max(0, int(g - tolerance)), min(255, int(g + tolerance)))
    b = random.randint(max(0, int(b - tolerance)), min(255, int(b + tolerance)))

    print(f"test(Color({r},{g},{b}), Pos({x},{y}));")
  except Exception as e:
    print(f"Error accessing pixel at ({x}, {y}): {e}")

if __name__ == "__main__":
  image_path = "test.png"  
  image = open_image(image_path)
  if image:
    for i in range(20):
      for j in range(10):
        x, y = 70 * i + 10, 100 *j + 10
        get_pixel_similar(image, x, y)
