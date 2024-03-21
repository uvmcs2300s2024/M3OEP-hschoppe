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

        //set new directory for image(s) to be uploaded into
        //https://www.w3schools.com/php/php_file_upload.asp

        $file_name = basename($_FILES["test-cases"]["name"]); //Replace test-cases with what we are feeding in
        
        // https://stackoverflow.com/questions/173868/how-can-i-get-a-files-extension-in-php
        $ext = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));

        if($ext == ".jpg" || $ext = ".png" || $ext == ".jpeg") {
            if(isset($_POST["submit"])) {
                $check = getimagesize($_FILES["test-cases"]["tmp_name"]);
                if($check !== false) {
                    $upload_valid = 1;
                } else {
                    upload_valid = 0;
                }
            }
        }

        $rand_number = uploads;

        $command_mkdir = escapeshellcmd("mkdir " . $rand_number);
        $output_mkdir = shell_exec($command_mkdir);

        //Copy files into folder
        $output_cp = shell_exec("cp locate.py " . $rand_number);
        $output_cp2 = shell_exec("cp find_x.py " . $rand_number);
        $output_cp3 = shell_exec("cp find_y.py " . $rand_number);

        if(move_uploaded_file($_FILES["test-cases"]["tmp_name"], $rand_number . "/" . $file_name)) {

            $output = shell_exec("cd " . $rand_number . ";chmod +x output.py;python output.py " . $file_name . ";cd ..");
            if ($output) {
                $image_name = $file_name;
            } else {
                $image_name = WHERESWALDO.png;
            }
            
        } else {
            $image_name = WHERESWALDO.png;
        }
        
        $x_val = shell_exec("cd " . $rand_number . ";chmod +x find_x.py;python find_x.py " . $image_name . ";cd ..");
        $y_val = shell_exec("cd " . $rand_number . ";chmod +x find_y.py;python find_y.py " . $image_name . ";cd ..");

        $final_name = $rand_number . $image_name;
        //Save path to file name - need to be able to access image file from js code

        //Display image

        //Run javascript program with two param, x and y


        ?>

        <!-- https://stackoverflow.com/questions/26065495/php-echo-to-display-image-html -->

        <img id="map" src="<?php echo $final_name;  ?>"> <!-- TODO: change path if needed -->
        <p id="printed_text"></p>

        <script>
            //How to take in x and y??
            var x_pos = "<?php echo $x_val; ?>";
            var y_pos = "<?php echo $y_val; ?>";

            //Height and width of image
            var image = "<?php echo $final_name; ?>";
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
