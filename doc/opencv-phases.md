# OpenCV Phases

## Phase: Initialize Camera

- Internal (cell phone)
- USB
- IP Camera
- while(true) getNextFrame() loop
- (re-)initialization of camera
- support IP parameters (get/post params)
- support OpenCV parameters
- parameter might be: zoom level, autofocus, white balance, ...
- apply parameters via JSON
- make this stateless and allow to repeat this any time

## Phase: Calibration of Map

- get a picture of the (empty) map
- create homography for later use to skip keypoint calculation
- make this stateless and allow to repeat this any time
- allow to use sub maps

## Phase: Color calibration (for tokens/dice)

- dice and token detection might use colors
- the player needs to put a reference card to the map
- the card is detected and compared to a given map
- we so learn the colors we expect vs. the colors the camera/printer/light generates

## Phase: sub maps

- A game might have sub maps
- for sub maps we just do a calibration of map step and save this map for later use
- if the sub map needs to be removed, we restore the original calibration map for the further steps

## Phase: Token detection

### Phase: Token definition

- name
- define a simple token: shape, color, width, height
- define an asset token: picture

### Phase: Preprocessing

- get next frame from camera
- detect board (this is optimized by just applying the homography and assuming it's on the same position)
- create diff frame (by using the reference frame we saved)
- detect light issues - if the map has "too much" diffs for a "too long" time, report this
- solution for "too much diffs" report bad light condition to user (or the user moved the map)
- user needs to remove all items from the map and we take a new empty map frame and a color calibration image
- bad but this might happen
- maybe implement a better background remove algorithm than we have or use a library for this
- Result: a frame with the same dimension as the original map just with the colored diffs and a black background

### Generic Token detection approach

- This works like a SQL query
- We pass a json string with multiple queries to the engine
- We get the answer to the queries

### Detection type: Is a token in a ROI?

- Mask the diff image with the ROI
- Phase -> Find token on the new diff

### Detection type: Where / in what ROI is token x?

- Phase -> Find token on the new diff

### Phase: Find token

#### Token detection type: color

- Instead of color we use the replaced color of the color calibration phase
- remove color expect the required one
- we might need to cache this frame for the whole token detection phase

#### Token detection type: shape

- Use the shape detect on the diff or on the color image
- Use the token's width/height to verify the detected area
- We can precalculate this when tokens are created (area calculations for triangles, rectangles, pentagons, ..)

#### Token detection type: image

- We use the diff image here
- Image detection is using the feature detector
- Precalculate the keypoints

#### Token inside ROI

- Detected tokens have a bounding box
- We can use the ROI Manager to check if the bonding box is inside
- Tokens might be detected as list of tokens




## Open

- Remote detection
- Remote button detection
- Specific handling of dice detection
