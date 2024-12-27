--- Represents a 2D position.
-- @field x number The x-coordinate.
-- @field y number The y-coordinate.
Pos = {x=0, y=0}

--- Creates a new Pos object.
-- @param x number The x-coordinate.
-- @param y number The y-coordinate.
-- @return Pos A new Pos object.
function Pos.new(x, y) end

--- Gets the string representation of the Pos object.
-- @return string
function Pos:to_string() end

--- Represents a color in RGB format.
-- @field r number The red component (0-255).
-- @field g number The green component (0-255).
-- @field b number The blue component (0-255).
Color = {}

--- Creates a new Color object.
-- @param r number The red component (0-255).
-- @param g number The green component (0-255).
-- @param b number The blue component (0-255).
-- @return Color A new Color object.
function Color.new(r, g, b) end

--- Gets the string representation of the Color object.
-- @return string
function Color:to_string() end

--- Gets a pointer to the screen's Mat object.
-- @return number An integer representing the pointer address.
function get_screen_mat_ptr() end

--- Adds a Mat object to memory and returns a pointer to it.
-- @param filename string The path to the image file.
function add_mat_from_file(filename) end

--- Updates the screen's Mat object.
function update_screen_mat() end
 
--- Finds a pattern within an image.
-- @param image_ptr number Pointer to the image (cv::Mat).
-- @param pattern_ptr number Pointer to the pattern (cv::Mat).
-- @param similarity number (optional) The similarity threshold (0.0-1.0, default 1.0).
-- @return Pos The position of the match, or Pos(-1, -1) if not found.
function find_pattern(image_ptr, pattern_ptr, similarity) end

--- Checks if a pattern is present at a specific position within an image.
-- @param image_ptr number Pointer to the image (cv::Mat).
-- @param pattern_ptr number Pointer to the pattern (cv::Mat).
-- @param pos Pos The position to check.
-- @param similarity number (optional) The similarity threshold (0.0-1.0, default 1.0).
-- @return boolean True if the pattern is found at the position, false otherwise.
function is_pattern_at(image_ptr, pattern_ptr, pos, similarity) end

--- Gets the color of a pixel in an image.
-- @param image_ptr number Pointer to the image (cv::Mat).
-- @param pos Pos The position of the pixel.
-- @return Color The color of the pixel, or Color(-1, -1, -1) on error.
function get_pixel_color(image_ptr, pos) end

--- Checks if a pixel's color is equal to a given color.
-- @param image_ptr number Pointer to the image (cv::Mat).
-- @param pos Pos The position of the pixel.
-- @param col Color The color to compare with.
-- @return boolean True if the colors are equal, false otherwise.
function is_pixel_color_equal(image_ptr, pos, col) end

--- Checks if a pixel's color is equal to given RGB values.
-- @param image_ptr number Pointer to the image (cv::Mat).
-- @param pos Pos The position of the pixel.
-- @param r number The red component (0-255).
-- @param g number The green component (0-255).
-- @param b number The blue component (0-255).
-- @return boolean True if the colors are equal, false otherwise.
function is_pixel_color_equal_rgb(image_ptr, pos, r, g, b) end