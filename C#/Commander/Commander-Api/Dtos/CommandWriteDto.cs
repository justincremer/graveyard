using System.ComponentModel.DataAnnotations;

namespace Commander.Dtos
{
    public class CommandWriteDto
    {
        [Required]
        [MaxLength(50)]
        public string Name { get; set; }

        [Required]
        [MaxLength(250)]
        public string Description { get; set; }
        
        [Required]
        [MaxLength(25)]
        public string Platform { get; set; }
    }
}