
/* Start of JavaScript Coding Part */

document.querySelector(".menu").addEventListener("click", () => {
  document.querySelectorAll(".target").forEach((item) => {
    item.classList.toggle("change");
});
});
document.querySelectorAll(".wrapper").forEach((item) => {
    item.addEventListener("click",()=> {
        document.querySelectorAll(".target").forEach((item) => {
            item.classList.remove("change");

        });
    });
  
});

const videos = document.querySelectorAll(".video");

videos.forEach((video) => {
    video.addEventListener("mouseover",() =>{
            video.play();
        });
        video.addEventListener("mouseout", () => {
         video.pause();

    
        });
});

// Existing JavaScript code...

// Existing JavaScript code...








document.addEventListener("DOMContentLoaded", () => {
    window.scrollTo(0, 0); // Start at top of the page
  
    // Event listeners for Reserve buttons in car cards
    document.querySelectorAll('.reserve-btn').forEach(button => {
      button.addEventListener('click', (e) => {
        const carName = e.target.dataset.car;
        const carImageSrc = e.target.closest('.card').querySelector('.card-img').src;
  
        // Update reservation section with car details
        document.querySelector('.section-reservation h1').textContent = `Reserve ${carName}`;
        document.querySelector('.reservation-car-img').src = carImageSrc;
        document.getElementById('reservation-section').style.display = 'block';
  
        // Scroll to the reservation section
        document.getElementById('reservation-section').scrollIntoView();
      });
    });
  
    // Handling reservation form submission
    document.querySelector('.reservation-form').addEventListener('submit', (e) => {
      e.preventDefault(); // Prevent default form submission
      if (e.target.checkValidity()) {
        alert('Car Reserved!');
        e.target.reset(); // Reset form
        document.getElementById('reservation-section').style.display = 'none'; // Hide reservation section
      } else {
        e.target.reportValidity(); // Show validation errors
      }
    });
  
    // Go Back button functionality
    document.querySelector('.go-back-btn').addEventListener('click', () => {
      document.getElementById('reservation-section').style.display = 'none';
      document.querySelector('.reservation-form').reset(); // Reset form when going back
    });
  });
  
  
      

/* END of JavaScript Coding Part */