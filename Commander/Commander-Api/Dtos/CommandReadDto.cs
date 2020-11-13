using System.ComponentModel.DataAnnotations;

namespace Commander.Dtos
{
    public class CommandReadDto : CommandWriteDto
    {        
        [Required]
        public int Id { get; set; }
    }
}