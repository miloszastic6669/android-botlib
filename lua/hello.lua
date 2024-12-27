local p = Pos.new(30,20);

local image = get_screen_mat_ptr()

print(image)

local col = get_pixel_color(image, p)

print(col)
