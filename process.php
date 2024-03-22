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

        $file_name = basename($_FILES["test-cases"]["name"]);
        echo $file_name; 
        //Replace test-cases with what we are feeding in
        
        // https://stackoverflow.com/questions/173868/how-can-i-get-a-files-extension-in-php
        $ext = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));
        echo $ext;

        if($ext == "jpg" || $ext = "png" || $ext == "jpeg") {
            if(isset($_POST["submit"])) {
                $check = getimagesize($_FILES["test-cases"]["tmp_name"]);
                if($check !== false) {
                    $upload_valid = 1;
                } else {
                    $upload_valid = 0;
                }
            } else {
                $upload_valid = 0;
            }
        } else {
            $upload_valid = 0;
        }

        echo $upload_valid; //Success!

        $final_name = basename( $_FILES["test-cases"]["name"]);
        $file_size =  $_FILES["test-cases"]["size"];
        $fileType = strtolower(pathinfo($file_name,PATHINFO_EXTENSION));

        $rand_number = 'uploads';
        echo $rand_number;
        echo "    ";
        echo $file_size; //Works through here

        $command_mkdir = escapeshellcmd("mkdir " . $rand_number);
        $output_mkdir = shell_exec($command_mkdir);

        echo "  Made it here!";

        //Copy files into folder
        $run_cp = escapeshellcmd("cp locate.py " . $rand_number);
        $output_cp = shell_exec($run_cp);
        $run_cp2 = escapeshellcmd("cp find_x.py " . $rand_number);
        $output_cp2 = shell_exec($run_cp2);
        $run_cp3 = escapeshellcmd("cp find_y.py " . $rand_number);
        $output_cp3 = shell_exec($run_cp3);
        $run_img = escapeshellcmd("cp " . $file_name . " " . $rand_number);
        $output_img = shell_exec($run_img);

        echo " yee to the haw";

        if(move_uploaded_file($_FILES["test-cases"]["tmp_name"], $rand_number . "/" . $file_name)) {

            $command_output = escapeshellcmd("cd " . $rand_number . ";chmod +x locate.py;python locate.py " . $file_name . ";cd ..");
            $output = shell_exec($command_output);
            echo "okay";
            echo $output;
            if ($output) {
                $image_name = $file_name;
                echo "dokey";
            } else {
                $image_name = WHERESWALDO.png;
                echo "oops";
            }
            echo $image_name;
            
        } else {
            $image_name = WHERESWALDO.png;
            echo "zoinks";
        }

        echo "wowzers!";




        ?>

        
    </body>
</html>
