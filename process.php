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
        
        $file_name = basename($_FILES["test-cases"]["name"]);
        
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

        //Run javascript program


        ?>

        <!-- https://stackoverflow.com/questions/26065495/php-echo-to-display-image-html -->

        <img src="images/gallery/<?php echo $image; ?>"> <!-- TODO: change path if needed -->
    </body>
</html>
