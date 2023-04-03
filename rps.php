<?php
$options = ['rock', 'paper', 'scissors'];

// Prompt the user to select an option
echo "Choose rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN)));

// Generate a random choice for the computer
$computer_choice = $options[array_rand($options)];

// Announce the winner of the game
if ($user_choice == $computer_choice) {
    echo "It's a tie! Both chose $user_choice.\n";
} elseif (($user_choice == 'rock' && $computer_choice == 'scissors') ||
          ($user_choice == 'paper' && $computer_choice == 'rock') ||
          ($user_choice == 'scissors' && $computer_choice == 'paper')) {
    echo "Congratulations! You won! The computer chose $computer_choice.\n";
} else {
    echo "Sorry, you lost. The computer chose $computer_choice.\n";
}
?>

