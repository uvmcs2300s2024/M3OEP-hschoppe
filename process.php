<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <!-- TODO: Update the author -->
        <meta name="author" content="Hailey Schoppe">
        <title>File Testing!</title>
        <!-- TODO: Update the description -->
        <meta name="description" content="This page is for verifying ">
        <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    </head>
    <body>
    	<header>
    		<h2>Where's Waldo?</h2>
    		<!-- TODO: Change this h3 to your function name -->
    		<h3>M3 Open Ended Project - Hailey Schoppe - CS2300</h3>
    	</header>
        <?php
        
        $file_name = basename($_FILES["test-cases"]["name"]); //Replace test-cases with what we are feeding in
        //Delete name?? name should be what is witheld - so update that as well perchance
        
        //Confirm file exists and get Waldo x/y
        if (file_exists($file_name)) {
            // https://stackoverflow.com/questions/173868/how-can-i-get-a-files-extension-in-php
            $ext = pathinfo($file_name, PATHINFO_EXTENSION);

            if ($ext == "jpg" || $ext == "jpeg" || $ext == "png") {
                // Open python file with image
                $output = shell_exec("python locate.py " . $file_name);
                if ($output == true) {
                    $image = $file_name;
                    $x_val = shell_exec("python find_x.py" . $file_name);
                    $y_val = shell_exec("python find_y.py" . $file_name);
                } else {
                    $file_name = "waldo.png";
                }
            } else {
                echo "File has invalid extension. Please submit a valid image file in the directory.";
            }

        } else {
            echo "File does not exist. Please submit a valid image file in the directory.";
        }

        //Display image

        //Run javascript program with two param, x and y


        ?>

        <!-- https://stackoverflow.com/questions/26065495/php-echo-to-display-image-html -->

        <img id="map" src="images/gallery/<?php echo $image; ?>"> <!-- TODO: change path if needed -->
        <p id="printed_text"></p>

        <script>
            //How to take in x and y??
            var x_pos = "<?php echo $x_val; ?>";
            var y_pos = "<?php echo $y_val; ?>";

            //Height and width of image
            var image = "<?php echo $file_name; ?>";
            //https://stackoverflow.com/questions/623172/how-to-get-the-image-size-height-width-using-javascript
            //TODO - Double check
            var width = document.querySelector(image).offsetWidth;
            var height = document.querySelector(image).offsetHeight;
            //Use pythag. theorem
            var counter = 0;

            var target = {
                x: x_pos;
                y: y_pos;
            }
            $("#map").click(function (event) {
                counter++;
                //Distance
                
                var x_difference = event.offsetX - target.offsetX;
                var y_difference = event.offsetY - target.offsetY;
                var difference = Math.sqrt((x_difference * x_difference) + (y_difference * y_difference));
                
                var print_distance;
                if (distance < 25) {
                    print_distance = "Very close!";
                } else if (distance < 50) {
                    print_distance = "Close!";
                } else if (distance < 100) {
                    print_distance = "Pretty close";
                } else if (distance < 200) {
                    print_distance = "Pretty far";
                } else {
                    print_distance =  "Quite far";
                }

                $("printed_text").text(print_distance);
                if (distance < 8) {
                    alert("Congrats! You found him in " + counter + " guesses!");
                }

            });


        </script>
    </body>
</html>
