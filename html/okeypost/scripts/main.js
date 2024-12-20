
let btnEntry = document.querySelector('#btnEntry');
let modal = document.querySelector('#modal');
let btnClose = document.querySelector('.close');
let body = document.querySelector('body');


openModal = () => {
    modal.classList.add("open");
    body.style.overflow = "hidden";
    modal.style.cursor = "default";
}

closeModal = () => {
    modal.classList.remove("open")
    body.style.overflow = "visible";
}

btnEntry.addEventListener('click', openModal);
btnClose.addEventListener('click', closeModal);