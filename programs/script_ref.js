// script.js
document.addEventListener('DOMContentLoaded', (event) => {
    var modal = document.getElementById("myModal");
    var btn = document.getElementById("openModalBtn");
    var span = document.getElementsByClassName("close")[0];

    // When the user clicks the button, open the modal
    btn.onclick = function() {
        modal.style.display = "block";
    }

    // When the user clicks on <span> (x), close the modal
    span.onclick = function() {
        modal.style.display = "none";
    }

    // When the user clicks anywhere outside of the modal, close it
    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }

    // Handle form submission
    var form = document.getElementById("modalForm");
    form.onsubmit = function(event) {
        event.preventDefault(); // Prevent the default form submission

        // Get the form data
        var name = document.getElementById("name").value;
        var email = document.getElementById("email").value;

        // Process the data (e.g., send it to the server or display it)
        console.log("Name: " + name);
        console.log("Email: " + email);

        // Close the modal after submission
        modal.style.display = "none";

        // Optionally, reset the form
        form.reset();
    }
});
