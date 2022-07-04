// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {
    let navItems = document.querySelectorAll(".nav-link");
    console.log(navItems.length);


    for (let i = 0; i < navItems.length; i++) {
        navItems[i].addEventListener("click", function() {
            Array.from(navItems, navItem => navItem.classList.remove('current'));
            navItems[i].classList.add('current');
        });
    }

    console.log(navItems.length);

})