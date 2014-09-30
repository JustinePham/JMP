var main = function() {
  $('.dropdown-toggle').click(function() {
    $('.dropdown-menu').toggle();
  });
  
  $('.arrow-next').click(function() {
  // if arrow is clicked, next dot becomes current.
  // toggle the the class .active-dot to var currentDot...
    var currentDot = $('.active-dot');
    var nextDot = currentDot.next();
    
  // next slide becomes the current slide.  
  // add class toggle currentSlide to active-slide.
    var currentSlide = $('.active-slide');
    var nextSlide = currentSlide.next();

    if(nextSlide.length === 0) {
      nextSlide = $('.slide').first();
      nextDot = $('.dot').first();
    }
    // remove slider and fade to the next slide at the same time
    // remove the class. add active class to the next slide. 
    currentSlide.fadeOut(600).removeClass('active-slide');
	nextSlide.fadeIn(600).addClass('active-slide');

    currentDot.removeClass('active-dot');
    nextDot.addClass('active-dot');

  });

  $('.arrow-prev').click(function() {
    var currentSlide = $('.active-slide');
    var currentDot = $('.active-dot');

    var prevSlide = currentSlide.prev();
    var prevDot = currentDot.prev();

    if(prevSlide.length === 0) {
      prevSlide = $('.slide').last();
      prevDot = $('.dot').last();
    }   
    currentSlide.fadeOut(600).removeClass('active-slide');
	prevSlide.fadeIn(600).addClass('active-slide');

	currentDot.removeClass('active-dot');
    prevDot.addClass('active-dot');
  });
}

$(document).ready(main);
